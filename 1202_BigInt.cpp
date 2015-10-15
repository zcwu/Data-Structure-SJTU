#include <iostream>

using namespace std;

class list {
private:
    struct node {
        int date;
        node *prev, *next;

        node():next(NULL),prev(NULL) {}
        };

    node *head, *tail;

public:
    list();
    list(const list &other);
    list &operator=(const list &other);
    ~list() {clear(); delete head; delete tail;}
    void create(int a);
    void oppo_create(int a);
    list add(const list &other);
    void display();
    void clear();
};

list::list()
{
    head = new node;
    tail = new node;

    head->next = tail;
    tail->prev = head;
}

list::list(const list &other)
{
    head = new node;
    tail = new node;

    head->next = tail;
    tail->prev = head;

    node *p = other.head->next;

    while (p != other.tail){
        create(p->date);
        p = p->next;
    }
}

list &list::operator=(const list &other)
{
    node *p = other.head->next;

    while (p != other.tail){
        create(p->date);
        p = p->next;
    }

    return *this;
}

void list::create(int a)
{
    node *tmp;
    tmp = new node;
    tmp->date = a;

    tmp->prev = tail->prev;
    tmp->next = tail;
    tail->prev->next = tmp;
    tail->prev = tmp;
}

void list::oppo_create(int a)
{
    node *tmp;
    tmp = new node;
    tmp->date = a;

    tmp->prev = head;
    tmp->next = head->next;
    head->next = tmp;
    head->next->prev = tmp;
}

void list::display()
{
    node *p = head->next;

    while (p != tail){
        cout << p->date;
        p = p->next;
    }
}

list list::add(const list &other)
{
    list tmp;
    int sum, carry = 0; 

    node *p, *q, *r;
    p = tail->prev;
    q = other.tail->prev;

    while ((p != head) && (q != other.head)){
        sum = p->date + q->date + carry;

        if (sum >= 10) {
            tmp.oppo_create(sum - 10);
            carry = 1;
        }
        else {tmp.oppo_create(sum); carry = 0;}

        p = p->prev; q = q->prev;
    }

    if (p == head){
        while (q != other.head){
            sum = q->date + carry;
            if (sum >= 10){
                tmp.oppo_create(sum - 10);
                carry = 1;
                }
            else {tmp.oppo_create(sum); carry = 0;}

            q = q->prev;
        }
    }

    if (q == other.head){
        while (p != head){
            sum = p->date + carry;
            if (sum >= 10){
                tmp.oppo_create(sum - 10);
                carry = 1;
                }

            else {tmp.oppo_create(sum); carry = 0;}

            p = p->prev; 
        }
    }

    if (carry == 1){
        tmp.oppo_create(1);
    }

    return tmp;
}

void list::clear()
{
    node *p = head->next, *q;
    head->next = tail;
    tail->prev = head;
    while (p != tail) {
        q = p->next;
        delete p;
        p = q;
    }
}

int main()
{
    list l1, l2, l3;
    char ch;

    while ((ch = cin.get()) != '\n') l1.create(ch - '0');
    while ((ch = cin.get()) != '\n') l2.create(ch - '0');

    l3 = l1.add(l2);

    l3.display();

    return 0;
}
