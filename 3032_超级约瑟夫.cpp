#include <iostream>
#include <cstring>

using namespace std;

class LongLongInt{
    friend LongLongInt operator+(const LongLongInt &, const LongLongInt &);
    friend ostream &operator<<(ostream &, const LongLongInt &);
    friend istream &operator>>(istream &, LongLongInt &);
    friend LongLongInt operator-(const LongLongInt &, const LongLongInt &);
    friend bool operator>(const LongLongInt &,const LongLongInt &);
private:
    char *num;
public:
    LongLongInt(const char *n = "");
    LongLongInt(const LongLongInt &);
    LongLongInt &operator=(const LongLongInt &);

};

LongLongInt::LongLongInt(const char *n)
{
    if (strcmp(n, "0") == 0) n = "";
    int len = strlen(n);

    num = new char [len + 1];
    for (int i = 0; i < len; ++i) num[len - i - 1] = n[i];
    num[len] = '\0';
}

LongLongInt::LongLongInt(const LongLongInt &other)
{
    num = new char [strlen(other.num) + 1];
    strcpy(num, other.num);
}

LongLongInt &LongLongInt::operator=(const LongLongInt &right)
{
    if (this == &right) return *this;

    delete num;

    num = new char [strlen(right.num) + 1];
    strcpy(num, right.num);

    return *this;
}

ostream &operator<<(ostream &os, const LongLongInt &obj)
{
    for (int i = strlen(obj.num) - 1; i >= 0; --i) os << obj.num[i];
    if (strlen(obj.num) == 0) os << 0;

    return os;
}

istream &operator>>(istream &is, LongLongInt &obj)
{
    char ch[2000]; int i;

    is.getline(ch, 2000);

    int len = strlen(ch);
    obj.num = new char [len + 1];

    for (i = 0; i < len; ++i) obj.num[i] = ch[len - i - 1];
    obj.num[i] = '\0';

    return is;
}

LongLongInt operator+(const LongLongInt &n1, const LongLongInt &n2)
{
    LongLongInt n;
    int len1 = strlen(n1.num), len2 = strlen(n2.num);
    int minlen = (len1 > len2 ? len2 : len1);
    int len = (len1 > len2 ? len1 : len2) + 1;
    int carry = 0, result, i;

    delete n.num;

    n.num = new char [len + 1];
    for(i = 0; i < minlen; ++i){
        result = n1.num[i] - '0' + n2.num[i] - '0' + carry;
        n.num[i] = result % 10 + '0';
        carry = result / 10;
    }

    while (i < len1) {
        result = n1.num[i] - '0' + carry;
        n.num[i] = result % 10 + '0';
        carry = result / 10;
        ++i;
    }

    while (i < len2) {
        result = n2.num[i] - '0' + carry;
        n.num[i] = result % 10 + '0';
        carry = result / 10;
        ++i;
    }

    if (carry != 0) n.num[i++] = carry + '0';
    n.num[i] = '\0';

    if (i != len) {
        char *tmp = n.num;
        n.num = new char [len];
        strcpy(n.num, tmp);
        delete tmp;
    }

    return n;
}

LongLongInt operator-(const LongLongInt &n1, const LongLongInt &n2)
{
    LongLongInt n;
    int len1 = strlen(n1.num), len2 = strlen(n2.num);
    int minus = 0, i;
    char *tmp;

    tmp = new char [len1 + 1];
    for (i = 0; i < len2; ++i){
        tmp[i] = n1.num[i] - n2.num[i] - minus;
        if (tmp[i] < 0) {tmp[i] += 10; minus = 1;}
        else minus = 0;
        tmp[i] += '0';
    }

    while (i < len1) {
        tmp[i] = n1.num[i] - '0' - minus;
        if (tmp[i] < 0) {tmp[i] += 10; minus = 1;}
        else minus = 0;
        tmp[i] += '0';
        ++i;
    }

    do {
        --i;
    } while (i >= 0 && tmp[i] == '0');

    tmp[i + 1] = '\0';

    delete n.num;
    n.num = new char [i + 2];
    strcpy(n.num, tmp);
    delete tmp;

    return 0;
}

bool operator>(const LongLongInt &n1,const LongLongInt &n2)
{
    int len1=strlen(n1.num),len2=strlen(n2.num);
    if (len1>len2) return true;
    else if(len1<len2) return false;

    for (int i=len1-1;i>=0;--i)
    {
        if(n1.num[i]>n2.num[i]) return true;
        else if(n1.num[i]<n2.num[i]) return false;
    }

    return false;
}

int main()
{
    char *temp;
    temp = new char[1001];
    cin.getline(temp,1001);
    LongLongInt a(temp),b("1"),c("1"),tmp,res,yuan("1");
    while (a > b)
    {
        c=c+c;
        b=b+c;
    }
    b = b-c;
    tmp= a-b;
    res = tmp + tmp;
    res = res - yuan;
    cout<<res;

    delete [] temp;

    return 0;
}

