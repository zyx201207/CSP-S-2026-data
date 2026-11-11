#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;
ll n,m,ans,a[N],sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(ll i=1;i<=n;i++){
        int l=0,r=i,u;
        while(l+1<r){
            int mid=(l+r)>>1;
            if(sum[mid]-a[i]*mid<=m-a[i]*i+sum[i])r=mid;
            else l=mid;
        }
        if(sum[l]-a[i]*l<=m-a[i]*i+sum[i])u=l;
        else u=r;
        ans=max(ans,i-u);
    }
    cout<<ans<<"\n";
    return 0;
}
