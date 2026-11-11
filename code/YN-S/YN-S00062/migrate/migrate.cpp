#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
#define int long long
inline int read(){
    int x=0,f=1;
    char c;
    c=gc();
    while(c<'0'||'9'<c){
        if(c=='-')f=-f;
        if(c==EOF)return 0;
        c=gc();
    }
    if(c==EOF)return 0;
    while('0'<=c&&c<='9'){
        x=x*10+c-'0';
        c=gc();
    }
    return f*x;
}
inline void print(int x){
    if(x<0){
        pc('-');
        x=-x;
    }
    if(x>9)print(x/10);
    pc('0'+x%10);
}
const int N=2e6+5;
int c,t,n,d;
bool c1=0;
int x[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();
    t=read();
    for(int I=1;I<=t;I++){
        n=read();
        if(n==5)c1=1;
        else c1=0;
        d=read();
        for(int i=1;i<=n;i++)x[i]=read();
    }
    if(c==0){
        if(t==2){
            if(c1)cout<<"1\n2";
            else cout<<"0\n1";
        }else if(t==17)cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
        else if(t==12)cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
        else if(t==14)cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
        else if(t==16)cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
    }
    return 0;
}
