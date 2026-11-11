#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define endl '\n'


ll en[10005];
int n;
ll m;
pair<bool,ll> check(int k){
    int cost=m,ans=0;
    for(int i=0;en[i]<=k;i++){
        cost-=k-en[i];
        cout<<k<<" "<<en[i]<<" "<<cost<<endl;
        if(cost<0)return {0,1};
        ans=i;
    }
    return {1,ans+1};
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    ll ans=0;
    for(int i=0;i<n;i++)cin>>en[i];
    sort(en,en+n);
    int l=0,r=n-1;
    while(l<r){

          //  cout<<l<<" "<<r<<endl;
        int k=(l+r)/2+1;
        pair<bool,ll> res=check(en[k]);
        if(res.first){
            l=k;
            ans=max(ans,res.second);
        }
        else r=k-1;
    }
    cout<<ans;
    return 0;
}
