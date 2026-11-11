#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using db=double;
using ldb=long double;
ll n,m;
// int cs[(ll)5e5+5];
// int ss[(ll)3e5+5];
// int ans[(ll)3e5+5];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    
    //Write Code HERE!!!!!!!!!
    int cs[(ll)5e2+5]={0};int ss[(ll)3e2+5]={0};int ans[(ll)3e2+5]={0};
    cin>>n>>m;
    for(ll i=1;i<=n;++i){
        cin>>cs[i];
    }
    for(ll i=n;i>=1;--i){
        if(ss[cs[i]]){
            continue;
        }
        ss[cs[i]]=i;
    }
    for(ll i=1;i<=n;++i){ll j=n;
        for(;j>=i;--j){
            if(ss[cs[j]]==0){
                
                break;
            }
        }
        for(;j<=n;++j){
            ans[cs[j]]++;
        }
    }
    for(ll i=1;i<=m;++i){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

    return 0;
}
