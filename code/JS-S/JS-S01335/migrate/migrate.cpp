#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int a[N];
int read(){
    int s=0,k=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')k=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=s*10+(ch-'0');
        ch=getchar();
    }
    return s*k;
}
void print(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x<=9){
        putchar(x+'0');
        return;
    }
    print(x/10);
    putchar(x%10+'0');
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;
    C=read(),T=read();
    srand(time(0));
    while(T--){
        cout<<rand()<<'\n';
    }
    return 0;
}