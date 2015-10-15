#include <iostream>

using namespace std;

template<class T>
class list{
friend void operator+(const list &obj1, const list &obj2)
{
    list tmp(0);
    node *p=obj1.head->next;
    node *q=obj2.head->next;

    for(int i=0;i<obj2.len;i++)
    {
        tmp.insert(q->data);
        q=q->next;
    }
    for(int i=0;i<obj1.len;i++)
    {
        tmp.insert(p->data);
        p=p->next;
    }
    tmp.print();
}

private:
    struct node{
        T data;
        node * next;
        node(): next(NULL) {};
        node(const T &x):next(NULL){data = x;}
    };

    node *head;
    int len;

public:
    list(int
         lenth = 0){head = new node;

    len = lenth;

    for (int i = 0; i < len; ++i){
        T tmp;
        cin >> tmp;
        node *p = new node (tmp);
        p->next = head->next;
        head->next = p;
    }}

    ~list() {clear(); delete head;}
    void clear();
    void insert(const T &x);
    void print();
    list &operator=(const list &other);

};

template<class T>
void list<T>::clear()
{
    node *p = head->next, *q;
    head->next = NULL;

    while (p != NULL){
        q = p->next;
        delete p;
        p = q;
    }
}

template<class T>
void list<T>::insert(const T &x)
{
    node *p = new node (x);

    p->next = head->next;
    head->next = p;
}

template<class T>
void list<T>::print()
{
    node *p = head->next;
    while (p != NULL){
        cout << p->data << ' ';
        p = p->next;
    }
}

int main( )
{
    char type[7];
    for(int i=0;i<7;i++)
    {
        type[i]='\0';
    }
    cin.getline(type,7);
    int n,m;
    cin>>n>>m;
    if(type[0]=='i')
    {
        list <int> list1(n),list2(m);list1+list2;
    }
    if(type[0]=='d')
    {
        list <double> list1(n),list2(m);list1+list2;
    }
    if(type[0]=='c')
    {
        list <char> list1(n),list2(m);list1+list2;
    }
    return 0;
}
