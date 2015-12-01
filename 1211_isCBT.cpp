#include <iostream>

using namespace std;

template<class T>
class Queue{
private:
    struct node {
        T data;
        int flag;
        node *next;
        node (const T &w, node *n = NULL)
        {
            data = w;
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
    void enQueue(const T &w);
    T deQueue();
    T getHead() {
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

template<class T>
Queue<T>::~Queue()
{
    node *tmp;
    while (front != NULL){
        tmp = front;
        front = front->next;
        delete tmp;
    }
}

template<class T>
void Queue<T>::enQueue(const T &w)
{
    if (rear == NULL) front = rear = new node(w);
    else {
        rear->next = new node(w);
        rear = rear->next;
    }
}

template<class T>
T Queue<T>::deQueue()
{
    node *tmp = front;
    T value = front->data;

    front = front->next;

    if (front == NULL) rear = NULL;

    delete tmp;

    return value;
}


class BinaryTree{
    //friend bool operator==(const BinaryTree &t1, const BinaryTree &t2);
    //friend bool isEqual(const BinaryTree &t1, const BinaryTree &t2);
private:
    struct Node {
        Node *left, *right;
        int data;
        int flag = 0;

        Node(): left(NULL), right(NULL) {}
        Node(int item, Node *L = NULL, Node *R = NULL): data(item), left(L), right(R) {}
        ~Node() {}
    };
    Node *root;

public:
    BinaryTree(): root(NULL) {}
    BinaryTree(const int &value) {root = new Node(value);}
    BinaryTree(Node *p) {root = p;}
    ~BinaryTree() {clear();}

    bool isCompleteBinaryTree();

    void createTree();


    bool isEmpty() {return root == NULL;}

    void clear()
    {
        if (root != NULL) clear(root);
        root = NULL;
    }
private:
    void clear(Node *t)
    {
        if (t->left != NULL) clear(t->left);
        if (t->right != NULL) clear(t->right);
        delete t;
    }

};

void BinaryTree::createTree()
{
    int n, i, j;
    cin >> n;

    int dataArr[n][2];
    Node* nodeArr[n];

    for (i = 0; i < n; ++i) {
        cin >> dataArr[i][0] >> dataArr[i][1];
        nodeArr[i] = new Node(i + 1);
    }

    for (i = 0; i < n; ++i) {
        /*if (dataArr[i][0] == 0) {nodeArr[i]->left = NULL; nodeArr[i]->flag = 1;}
        else {nodeArr[i]->left = nodeArr[dataArr[i][0] - 1]; nodeArr[i]->left->flag = 1;}
        if (dataArr[i][1] == 0) {nodeArr[i]->right = NULL; nodeArr[i]->flag = 1;}
        else {nodeArr[i]->right = nodeArr[dataArr[i][1] - 1]; nodeArr[i]->right->flag = 1;}*/
        if (dataArr[i][0] != 0) {nodeArr[i]->left = nodeArr[dataArr[i][0] - 1]; nodeArr[i]->left->flag = 1;}
        if (dataArr[i][1] != 0) {nodeArr[i]->right = nodeArr[dataArr[i][1] - 1]; nodeArr[i]->right->flag = 1;}
    }

    for (i = 0; i < n; ++i) {
        if (nodeArr[i]->flag != 1) break;
    }

    root = nodeArr[i];
}

bool BinaryTree::isCompleteBinaryTree()
{
    Queue<Node*> que;
    que.enQueue(root);
    Node *tmp;

    //tmp = root;

    while ((tmp = que.deQueue()) != NULL) {
        que.enQueue(tmp->left);
        que.enQueue(tmp->right);
    }
    while (!que.isEmpty()) {
        tmp = que.deQueue();
        if (tmp != NULL) return false;
    }
    return true;
}

int main()
{
    BinaryTree tree;

    tree.createTree();

    //tree.preOrder();
    if (tree.isCompleteBinaryTree()) cout << 'Y' << endl;
    else cout << 'N' << endl;

    return 0;
}
