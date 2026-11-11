#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int N=5e5+10;

int n,m;
int a[N];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int p=1,cost=0,ans=0;
    for(int i=1;i<=n;i++){
        cost+=(i-p)*(a[i]-a[i-1]);
        while(cost>m){
            cost-=(a[i]-a[p]); p++;
        } 
        ans=max(ans,i-p+1);
    }
    cout<<ans<<'\n';
    return 0;
}