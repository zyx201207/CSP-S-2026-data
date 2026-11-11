#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q_rd(){
    char c;
    ll res=0,f=1;
    c=getchar();
    while(c<'0'||'9'<c){
        if(c=='-')f=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        res=(res<<3)+(res<<1)+c-48;
        c=getchar();
    }
    return f*res;
}
void solve(ll c){
    ll n=q_rd(),k=q_rd();
    for(int i=1;i<n;i++)
        ll x=q_rd(),y=q_rd();
    ll len=(n/2)-((k+1)/2);
    ll _len=(len+1)/2*(2-len%2);
    ll ans=(_len+1)*_len+_len+(len%2==0);
    if(k&1)ans+=_len+(len%2==0);
    printf("0\n");
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ll c=q_rd(),T=q_rd();
    while(T--){
        solve(c);
    }
    return 0;
}
