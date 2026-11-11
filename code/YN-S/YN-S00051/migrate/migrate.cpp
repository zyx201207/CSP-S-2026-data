#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int c,t;
ll a[N],ans[N],mx=0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll n,d;
    cin>>c>>t;
    while(t--){
    cin>>n>>d;
    if(n<=3){
        for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<"0"<<"\n";
    }
    if(n>3){
            a[n+1]=a[n]+d;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
    int cnt=1,zid=i,yid=i, k=0;
    while(cnt<=2){
    int l=a[zid];
    int r=upper_bound(a+1,a+n+1,l+d)-a;
    if(cnt==2){
    if(r-yid-1>=2)
        ans[i]+=min(r-yid-1,r-k+1),cnt=n;
    if(r-yid-1==0)
    cnt=n;
    if(r-yid-1==1)
        ans[i]+=min(r-k+1,1),zid=yid+1,yid=r-1;}
    if(cnt==1){
    if(r-yid-1>2)
        cnt=n;
    if(r-yid==1)
        cnt=n;
    if(r-yid-1==1)
        zid=yid+1,yid=r-1;
    if(r-yid-1==2)
        cnt=2,zid=yid+1,yid=r-1;}
     k=upper_bound(a+1,a+n+1,a[yid]+d)-a;
    }}

    for(int i=1;i<=n;i++)
        mx+=ans[i],ans[i]=0;
    cout<<mx<<"\n";
    mx=0;
    }
    }

    return 0;
}
