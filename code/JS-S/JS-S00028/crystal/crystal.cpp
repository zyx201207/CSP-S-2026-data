#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+50;
ll n,m,ans;
ll a[maxn],sum[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
    int l=1;
    for(int r=1;r<=n;r++){
        while(sum[r]-sum[l-1]-(l-1)*(a[r]-a[l-1])>m)l++;
        if(r-l+1>ans)ans=r-l+1;
    }
    cout<<ans;
    return 0;
}
