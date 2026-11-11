#include<bits/stdc++.h>
#define ll long long
#define pii pair<long long,long long>
using namespace std;
ll c,n,m,d,q;
vector<ll> a;
inline ll read(){
    ll x=0;
    int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-'){
            f=-1;
        }
        c=getchar();
    }
    while(isdigit(c)){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*f;
}
inline void co(ll x){
    if(x<0){
       putchar('-');
    }
    if(x>9){
        co(x/10);
    }
    putchar(x%10+'0');
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    return 0;
}
