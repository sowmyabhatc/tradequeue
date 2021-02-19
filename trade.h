#ifndef TRADE_H_INCLUDED
#define TRADE_H_INCLUDED
#include "appconst.h"
#include<stdint.h>
#include<uchar.h>

typedef struct _stock_queue_ Stock;

struct _stock_queue_{

    char32_t *name;
    char32_t *date;
    int32_t price;
    int32_t quantity;

};

typedef struct _queue_ Queue;

struct _queue_ {

    uint32_t size;
    uint32_t count;
    uint32_t rear;
    uint32_t front;
    Stock data[STOCK_LEN];

};

typedef struct _stock_result_ StockResult;

struct _stock_result_ {
    Stock data;
    uint32_t status;
};

Queue new_stock(uint32_t size);
Queue* Buy_new(Queue *q, char32_t* name,char32_t *date, int32_t price, int32_t quantity, StockResult *res);
Queue* Sell_old(Queue *q,int32_t quant,StockResult *res);
uint32_t trade_lookup(Queue *q,char32_t *name);
Queue* trade_topup(Queue *q,char32_t *comp,int32_t quant);



#endif // TRADE_H_INCLUDED
