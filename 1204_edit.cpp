#include <iostream>
#include <cstring>

using namespace std;

class list{

public:
	struct node{
		char data;
		node *next;
		node(const char& x, node *n = NULL):data(x),next(n){}
		node(node *n = NULL):next(n){}
	};
	node *head;
	int length0;
	list(){head = new node; length0 = 0;}
	~list(){clear(); delete head;}
	void clear(){
		node *tmp = head;
		while(tmp->next != NULL){
			tmp = tmp->next;
			delete head;
			head = tmp;
		}
		length0 = 0;
	}
	void insert(int index, const char* str){
		node *p = head;
		for(int i = 0; i < index-1; ++i){
			p = p->next;
		}
		int j = 0;
		char ch = str[j];
		while(ch !='\0'){
			p->next = new node(ch ,p->next);
			length0++;
			p = p->next;
			ch = str[++j];
		}
	}
	void remove(int index, int n){
		node *p = head, *tmp;
		for(int i = 0; i < index-1; ++i){
			p = p->next;
		}
		for (int i = 0; i < n; ++i){
			tmp = p->next;
			p->next = p->next->next;
			delete tmp;
			length0--;
		}
	}
	void print()const{
		node *tmp = head->next;
		while(tmp != NULL){
			cout << tmp->data;
			tmp = tmp->next;
		}
		cout << endl;
	}
};



bool Endif(char * s){
    for(int i = 0; i < 6; ++i) if (s[i] != '*')
    return false;
    if(s[6] != '\0') return false;
    return true;
}

void post_error(){cout << "Error!" << endl;}

void printlist(int n1, int n2, list *list0, int row_number){
    if (n1 > n2 or n1 <= 0 or n2 > row_number )
        {post_error(); return;}
    for(int i = n1-1; i < n2; i++)
        list0[i].print();
    return ;
}

void ins(int i, int j, const char *str, list *list0, int row_number){
    if( i <= 0 or i > row_number or j <= 0
      or j > (list0[i-1].length0+1) )
        {post_error(); return;}
    list0[i-1].insert(j, str);
}

void del(int i, int j, int num, list *list0, int row_number)
{
    if( i <= 0 or i > row_number or j <= 0 or num < 0
      or (j+num) > (list0[i-1].length0+1) or
      (j == 1 and num == list0[i-1].length0))
        {post_error(); return;}
    list0[i-1].remove(j, num);
}

bool Quitif(char *s){
    char *q = "quit";
    for (int i = 0; i < 5; ++i) if (s[i] != q[i]) return false;
    return true;
}

bool Listif(char *s){
    char *q = "list";
    for (int i = 0; i < 5; ++i) if (s[i] != q[i]) return false;
    return true;
}

bool Delif(char *s){
    char *q = "del";
    for (int i = 0; i < 4; ++i) if (s[i] != q[i]) return false;
    return true;
}

bool Insif(char *s){
    char *q = "ins";
    for (int i = 0; i < 4; ++i) if (s[i] != q[i]) return false;
    return true;
}


int main(){
	list row[200];
	int n = 0;

    char s0[2002];
	while(true)
	{
        cin.getline(s0,2002);
        if(Endif(s0)) break;
        row[n].insert(1,s0);
        n++;
	}

	cin >> s0;
	int a, b, c;
	char s1[2002];
	while (!Quitif(s0)){
        if (Listif(s0)) {
            cin >> a >> b;
            printlist(a, b, row, n);
        }
        if (Insif(s0)) {
            cin >> a >> b;
            cin.get();
            cin.getline(s1, 2002);
            ins(a, b, s1, row, n);
        }
        if (Delif(s0)){
            cin >> a >> b >> c;
            del(a, b, c, row, n);
        }
        cin >> s0;
	}

	printlist(1, n, row, n);

	return 0;
}
