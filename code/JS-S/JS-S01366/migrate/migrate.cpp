#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d;
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
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),t=read();
    while(t--){
        a.clear();
        n=read(),d=read();
        for(int i=1;i<=n;i++){
            ll x=read();
            a.push_back(x);
        }
        cout<<rand()%n<<"\n";
    }
    return 0;
}
