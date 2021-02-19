#include<stdint.h>
#include "trade.h"
#include <assert.h>
#include<string.h>

Queue new_stock(uint32_t size){

    if (size <= 5) {
        Queue q1 = {size,0,0,0,{"22-2-2020",0,0,0}};
        return q1;
    }

}
Queue* Buy_new(Queue *q, char32_t* name,char32_t *date, int32_t price, int32_t quantity, StockResult *res){
    assert (q != NULL);
    if(q->count < q->size){
        q->data[q->rear].price = price;
        q->data[q->rear].quantity = quantity;
        q->data[q->rear].name =  name;
        q->data[q->rear].date = date;

        q->rear = (q->rear+1) % q->size;
        ++q->count;
        res->status = QUEUE_OK;
    }
    else{
        q->data[q->front].price = price;
        q->data[q->front].quantity = quantity;
        q->data[q->front].name = name;
        q->data[q->front].date = date;

        q->front = (q->front+1) % q->size;
        res->status = QUEUE_OK;
    }
    return q;

}
Queue* Sell_old(Queue *q,int32_t quant,StockResult *res){

    assert (q != NULL);
    if(q->count != 0){
        if(quant < q->data[q->front].quantity){
                q->data[q->front].quantity -= quant;
        }
        else{
            res->data = q->data[q->front];
            q->front = (q->front+1)%q->size;
            --q->count;
            res->status = QUEUE_OK;
        }

    }
    else{
    res->status = QUEUE_EMPTY;
    }
    return q;
}

uint32_t trade_lookup(Queue *q,char32_t *name){

    for(int i=0;i<q->count;i++){
       if(strcmp(name, q->data[i].name)==0){
        return 1;
       }
    }
    return 0;

}

Queue* trade_topup(Queue *q,char32_t *comp,int32_t quant){

    for(int i=0;i<q->count;i++){
        if(strcmp(comp, q->data[i].name)==0){
        q->data[i].quantity += quant;
       }
    }
    return q;


}

