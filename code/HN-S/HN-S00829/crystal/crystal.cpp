#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N=5e5+5;
ll n,m;
ll sum;
ll a[N],pre[N],sum_pre[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll num=0,pos=n,ans=0;
    for(int i=n;i>=1;i--){
        if(pos<=0)break;
        while(pos>=1&&num+a[i]-a[pos-1]<=m){
            pos--;
            num+=(a[i]-a[pos]);
        }
        ans=max(ans,i-pos+1);
        num-=(i-pos)*(a[i]-a[i-1]);
    }
    cout<<ans;
    return 0;
}