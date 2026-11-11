#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll jl[110],jk[110]={1},rc[290000];
void solve(){
    ll n,m;
    cin>>n>>m;
    if(m==1){
        cout<<0;
        return;
    }
    for(ll i=1;i<=n;i++){
        cin>>rc[i];
        for(ll k=30;k>=0;k--){
            if((rc[i]&jk[k])!=0){
                jl[k]++;
            }
        }
    }
    ll temp1=0,temp2;
    for(ll i=1;i<=n;i++){
        temp1=0;
        for(ll k=30;k>=0;k--){
            if((rc[i]&jk[k])==0&&jl[k]>1){
                temp1+=jk[k];
            }
        }
        rc[i]=temp1;
    }
    sort(rc+1,rc+1+n);
    temp1=1;
    for(ll i=1;i<=n-m;i++){
        temp1=(temp1&rc[i]);
    }
    temp2=0;
    for(ll i=1;i<=30;i++){
        if(jl[i]>=2){
            temp2+=jk[i];
        }
    }
    cout<<temp2-temp1;
    return ;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(ll i=1;i<=50;i++){
        jk[i]=jk[i-1]*2;
    }
    ll T=1;
    while(T--){
        solve();
    }
    return 0;
}
