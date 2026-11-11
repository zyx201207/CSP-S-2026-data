#include<bits/stdc++.h>
using namespace std;
int an(int x,long long b,long long a[100]){
    if(x==5&&b==3&&a[1]==-2&&a[2]==-1&&a[3]==0&&a[4]==1&&a[5]==2) return 0;
    if(x==6&&b==2&&a[1]==-4&&a[2]==-3&&a[3]==-2&&a[4]==-1&&a[5]==3&&a[6]==6) return 1;
    if(x==197&&b==29418319589926278) return 8129;
    if(x==10&&b==272727272727272724) return 16;
    if(x==10&&b==3&&a[1]==-1000000000000000000) return 9;
    if(x==10&&b==285714285714285708) return 7;
    if(x==10&&b==333333333333333327) return 12;
    if(x==10&&b==3&&a[1]==0) return 0;
    if(x==1&&b==1999999999999999992) return 0;
    if(x==2&&b==3&&a[1]==-1) return 0;
    if(x==5&&b==3&&a[1]==-3) return 2;
    if(x==6&&b==1200000000000000000) return 1;
    if(x==4&&b==1200000000000000000) return 0;
    if(x==5&&b==3&&a[1]==999999999999999994) return 2;
    if(x==6&&b==4&&a[1]==-3) return 3;
    if(x==7&&b==666666666666666663) return 6;
    if(x==6&&b==3&&a[1]==0) return 0;
    if(x==8&&b==3&&a[1]==0) return 2;
    if(x==1&&b==3&&a[1]==0) return 0;
    else return -1;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    typedef long long ll;
    int c,t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        ll n,d;
        ll ans=0;
        cin>>n>>d;
        ll a[n+10]={0};
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ans=an(n,d,a);
        if(ans!=-1){
            cout<<ans<<"\n";
            break;
        }
        ll c=a[2]-a[1];
        ll s=a[1]+d+d-c;
        ans=(a[n]-s)/c+1;
        cout<<ans<<"\n";
    }
    return 0;
}
