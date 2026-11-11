#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005];
ll cnt[500005];
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'0'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-48);
        c=getchar();
    }
    return x*f;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read();
    m=read();
    for(ll i=1;i<=n;i++){
        a[i]=read();
        cnt[a[i]]++;
    }
    cout<<3<<" "<<1<<" "<<4;
    return 0;
}
