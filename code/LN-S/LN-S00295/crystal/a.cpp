#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005],b[500005],c[500005];
ll cnt,ans;;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    ll f=a[2]-a[1];bool ff=1;
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]!=f){ff=0;break;}
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)b[i]=a[n]-a[i];
    for(int i=1;i<=n;i++)c[i]=b[i]+c[i-1];
    if(!ff){
        ans=1;
        ll r=1,l=1;
        for(r=1;r<=n;r++){
            cnt=c[r]-c[l-1]-(r-l+1)*b[r];
            while(cnt>m){
                l++;
                cnt=c[r]-c[l-1]-(r-l+1)*b[r];
            }ans=max(ans,r-l+1);
        }
        cout<<ans<<endl;
    }
    else{
        ll r=1,l=1;
        for(r=1;r<=n;r++){
            cnt=c[r]-c[l-1]-(r-l+1)*b[r];
            if(cnt>m)break;
        }
        cout<<r-l+1<<endl;
    }
    return 0;
}
