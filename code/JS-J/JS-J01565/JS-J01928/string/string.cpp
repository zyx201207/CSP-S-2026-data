#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,pos=1,sum,a[200005];
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
struct node{
    ll v;
    char l;
}b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    n=read();
    char next_=' ';
    for(ll i=1;i<=n;i++){
        a[i]=read();
        sum+=a[i];
        char x;cin>>x;
        if(x==next_)b[pos].v+=a[i];
        else b[pos++].v=a[i];
        b[pos].l=x;
        next_=x;
    }
    ll ans=0,L=1;
    for(ll i=1;i<=pos;i++){
        if(b[i].l==b[pos-i+1].l)b[i].v-=min(b[i].v,b[pos-i+1].v),b[pos-i+1].v-=min(b[i].v,b[pos-i+1].v);
    }
    for(ll i=pos/2;i<=pos;i++)ans+=(b[i].v);
    cout<<sum-ans;
}