#include <stdio.h>
#include <stdlib.h>
#include "trade.h"
#include<assert.h>


void test_stock(){

    Queue q1 = new_stock(5);
    Queue *q = &q1;

    StockResult res;

    q = Buy_new(q, "APPLE","23-12-2020", 400, 50, &res);
    assert(q->count == 1);
    q = Buy_new(q, "MICROSOFT","24-12-2020", 500, 70, &res);
    assert(q->count == 2);
    q = Buy_new(q, "GOOGLE","25-12-2020", 1000, 100, &res);
    q = Buy_new(q, "NETFLIX","26-12-2020", 500, 110, &res);
    q = Buy_new(q, "AIRBNB","27-12-2020", 1500, 90, &res);
    assert(q->count == 5);
    assert(res.status == QUEUE_OK);
    q = Buy_new(q, "AMAZON","27-12-2020", 1500, 120, &res);
    assert(q->data[0].quantity==120);


    q = Sell_old(q, 50, &res);
    assert(q->count == 5);
    q = Sell_old(q, 20, &res);
    assert(q->count == 4);
    assert(res.status == QUEUE_OK);

    assert(trade_lookup(q,"APPLE")==0);
    assert(trade_lookup(q,"GOOGLE")==1);

    q = trade_topup(q, "GOOGLE", 50);
    assert(q->data[2].quantity == 150);

}

int main()
{
    test_stock();
    return 0;
}
