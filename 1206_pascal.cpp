#include <iostream>
#include <cstring>

using namespace std;

class Stack {
private:
    struct node {
        char *data;
        node *next;
        node(const char *ch, node *n = NULL){
            data = new char [strlen(ch) + 1];
            strcpy(data, ch);
            next = n;
        }

        node(): next(NULL) {}
        ~node() {}
    };

    node *head;
public:
    Stack() {head = NULL;}
    ~Stack();
    bool isEmpty() const {return head == NULL;}
    void push(const char *ch) {
        node *tmp = new node(ch, head);
        head = tmp;
    }
    char* pop() {
        node *tmp = head;
        char *x = tmp->data;
        head = head->next;
        delete tmp;
        return x;
    }
    char* top() const {return head->data;}
    //void input();
    //bool judge();
};

Stack::~Stack()
{
    node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main()
{
    char ch[201];
    bool flag1 = true, flag2 = false;
    Stack pascal;

    //cin >> ch; //strcmp(ch, "******") != 0

    while (cin >> ch){
        if (strcmp(ch, "begin") == 0 || strcmp(ch, "if") == 0) {pascal.push(ch);}

        /*if (strcmp(ch, "if") == 0) {
            if (pascal.isEmpty()) {flag1 = false; break;}
            else pascal.push(ch);
        }*/

        if (strcmp(ch, "then") == 0) {
            if (pascal.isEmpty()) {flag1 = false; break;}

            if (strcmp(pascal.top(), "if") == 0) {pascal.push(ch);}
            else {flag1 = false;  break;}
        }
        if (strcmp(ch, "else") == 0) {
            if (pascal.isEmpty()) {flag1 = false; break;}

            if (strcmp(pascal.top(), "then") == 0) {
                pascal.pop();
                pascal.pop();
                flag2 = true;
            }
            else {flag1 = false; break;}
        }
        if (strcmp(ch, "end") == 0) {
            if (pascal.isEmpty()) {flag1 = false; break;}

            /*if (strcmp(pascal.top(), "then") == 0) {
                pascal.pop();
                pascal.pop();
            }*/
            while (strcmp(pascal.top(), "then") == 0 || strcmp(pascal.top(), "if") == 0) {
                pascal.pop();
            }


            if (strcmp(pascal.top(), "begin") == 0) {pascal.pop(); flag2 = true;}
            else {flag1 = false; break;}
        }

        //cin >> ch;
    }
    if (!pascal.isEmpty()) {
        //cout << 0 << endl;
        //cout << pascal.top() << endl;
        //cout << strcmp(pascal.top(), "then") << ' ' << strcmp(pascal.top(), "if")  << endl;
        while ((!pascal.isEmpty()) && (strcmp(pascal.top(), "then") == 0 || strcmp(pascal.top(), "if") == 0)) {
            //cout << 3 << endl;
            //cout << pascal.top() << endl;
            pascal.pop();
        }
    }

    if (!pascal.isEmpty()) {flag1 = false;}

    if (flag1 == true) cout << "Match!" << endl;
    else cout << "Error!" << endl;
    //pascal.input();
    //cout << pascal.top() << endl;
    //while (!pascal.isEmpty()) cout << pascal.pop() << endl;

    return 0;
}
