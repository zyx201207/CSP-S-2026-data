#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+9;
ll a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    a[n+1]=a[n]+1;
    ll l=1,r=1,cost=0,ans=1;
    while(l<=n){
        while(cost<=m && r<=n){
            r++;
            cost+=(r-l)*(a[r]-a[r-1]);
        }
        ans=max(ans,r-l);
        cost-=(a[r]-a[l]);
        l++;
    }
    cout<<ans;
    return 0;
}
