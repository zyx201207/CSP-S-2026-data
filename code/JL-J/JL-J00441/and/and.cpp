#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll n,m,a[100000+10],tmax;
vector<ll> q;
ll sum(ll x,ll i){
    x&=a[i];
    return x;
}
void dfs(ll r,ll num){
    if(r==m){
        for(ll i=0;i<q.size();i++){
            if(q[i]>tmax){
                tmax=q[i];
            }
        }
        return ;
    }
    ll t=0;
    for(int i=r;i<num;i++){
        t=sum(t,i);
        q.push_back(t);
        dfs(r+1,num+1);
        q.pop_back();
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,m+1);
    cout<<tmax;
    return 0;
}
