#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define F1 freopen("crystal.in","r",stdin)
#define F2 freopen("crystal.out","w",stdout)
void io(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
ll n,m,a[500000+100],ans,use,sum[500000+100];
int main(){
    F1;F2;
    io();
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        ll l=1,r=i,mid=(l+r)/2,ul,ur;
        while(l<r&&!(l==ul&&r==ur)){
            ul=l;ur=r;
            mid=l+r>>1;
            if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m)r=mid;
            else l=mid;

        }
        ans=max(ans,((((i-l+1)*a[i]-(sum[i]-sum[l-1])<=m)?(i-l+1):(i-r+1))));
    }
    cout<<ans;
    return 0;
}
//RP++;
