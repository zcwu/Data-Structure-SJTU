#include <iostream>
#include "stdio.h"
//#include <iomanip>

using namespace std;

class Queue{
private:
    struct node {
        int time;
        node *next;
        node (const int w, node *n = NULL)
        {
            time = w;
            next = n;
        }
        node(): next(NULL) {}
        ~node() {}
    };

    node *front, *rear;

public:
    Queue() {front = rear = NULL;}
    ~Queue();
    bool isEmpty() {return front == NULL;}
    void enQueue(const int w);
    int deQueue();
    int getHead() {
        if (front == NULL) return -1;
        return front->time;
        }
    void print(){
        node *tmp = front;
        while (tmp != NULL) {
            cout << tmp->time << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

Queue::~Queue()
{
    node *tmp;
    while (front != NULL){
        tmp = front;
        front = front->next;
        delete tmp;
    }
}

void Queue::enQueue(const int w)
{
    if (rear == NULL) front = rear = new node(w);
    else {
        rear->next = new node(w);
        rear = rear->next;
    }
}

int Queue::deQueue()
{
    node *tmp = front;
    int value = front->time;

    front = front->next;

    if (front == NULL) rear = NULL;

    delete tmp;

    return value;
}

int main()
{
    int m, i, p, q, bcnt = 0, tcnt = 0, cnt = 1, ship = 0;
    Queue bus, truck;

    cin >> m;

    for (i = 0; i < m; ++i){
        cin >> p >> q;

        if (p == 0) {bus.enQueue(q); ++bcnt;}
        else {truck.enQueue(q); ++tcnt;}
    }

    double buswait = 0.0, truckwait = 0.0;
    double busAvrg, truckAvrg;

    if (bus.getHead() != 0 && truck.getHead() != 0) ++ship;

    for (i = 0; i < m; ++i){
        bool flag = false;

        if (cnt % 11 == 0) {++ship; cnt = 1; flag = true;}

        /*if (!(bus.getHead() > (ship - 1) * 10 && bus.getHead() <= ship * 10) &&
            !(truck.getHead() > (ship - 1) * 10 && truck.getHead() <= ship * 10) && !flag) {
                ++ship;
                cnt = 1;
                --i;
                continue;
            }*/
        if ((bus.getHead() > ship * 10) && (truck.getHead() > ship * 10) && !flag) {
                ++ship;
                cnt = 1;
                --i;
                continue;
            }

        if (!bus.isEmpty()) {

            if (cnt % 5 != 0 && bus.getHead() <= ship * 10){

                int value = bus.deQueue();

                buswait += ship * 10 - value;

                ++cnt;
                continue;
            }
            if (cnt % 5 == 0 && truck.isEmpty() && bus.getHead() <= ship * 10){
                int value = bus.deQueue();

                buswait += ship * 10 - value;

                ++cnt;
                continue;
            }
            if (cnt % 5 == 0 && !truck.isEmpty() && truck.getHead() > ship * 10 && bus.getHead() <= ship * 10){
                int value = bus.deQueue();

                buswait += ship * 10 - value;

                ++cnt;
                continue;
            }
        }
        if (!truck.isEmpty()) {

            /*if (cnt % 5 == 0 && truck.getHead() <= ship * 10){
                int value = truck.deQueue();

                truckwait += ship * 10 - value;

                ++cnt;
                continue;
            }

            if (cnt % 5 != 0 && truck.getHead() <= ship * 10){
                int value = truck.deQueue();

                truckwait += ship * 10 - value;

                ++cnt;
                continue;
            }
        }*/
        if (truck.getHead() <= ship * 10){
                int value = truck.deQueue();

                truckwait += ship * 10 - value;

                ++cnt;
                continue;
            }
        else {++ship; --i; cnt = 1;}

        }
    }

    if (bcnt == 0) bcnt = 1;
    if (tcnt == 0) tcnt = 1;

    busAvrg = buswait / bcnt;
    truckAvrg = truckwait / tcnt;


    //cout << setiosflags(ios::fixed) << setprecision(3) << busAvrg << ' ' << truckAvrg << endl;
    printf("%.3f %.3f", busAvrg, truckAvrg);

    return 0;

}
