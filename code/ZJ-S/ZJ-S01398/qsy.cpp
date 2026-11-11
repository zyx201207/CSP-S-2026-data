#include<bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define pb push_back
#define endl '\n'
using namespace std;
using pii=array<int,2>;
using ll=long long;
const int N=1e6+10;
inline void read(){}
template<class T,class...T2>
inline void read(T&ret,T2&...rest){
    ret=0;char c=gc();bool f=0;
    for(;!isdigit(c)&&c!=EOF;c=gc())f=c=='-';
    for(;isdigit(c);c=gc())ret=ret*10+c-'0';
    if(f)ret=-ret;
    read(rest...);
}
#define cin(...) read(__VA_ARGS__)
template<class T>
inline void print(T x){
    static int stk[40];
    int t=0,f=(x<0);
    if(f)x=-x;
    do stk[t++]=x%10;while(x/=10);
    if(f)pc('-');
    for(;t;pc(stk[--t]+'0'));
}
int main(){
    //freopen("file.in","r",stdin);
    //freopen("file.out","w",stdout);
    
    return 0;
}
//g++ qsy.cpp -o qsy -std=c++14 -Wall -Wextra -Og -g -Dlocal -fsanitize=address,undefined
//g++ qsy.cpp -o qsy -std=c++14 -O2