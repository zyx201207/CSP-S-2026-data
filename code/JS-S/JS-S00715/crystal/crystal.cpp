#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],pre[500005],d;
const int P=1e18;
int ans=0;
bool flag1=true;
bool flag2=true;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
            cin>>a[i];
            pre[i]=(pre[i-1]+a[i])%P;
            if(i>=2){
               if (a[i]!=a[i-1])flag1=false;
            }
            if (i==2)d=a[i]-a[i-1];
            if (i>2&&a[i]-a[i-1]!=d)flag2=false;
    }
    if (flag1){
        cout<<n;
        return 0;
    }
    if (flag2){
        for (int i=1;i<=n;i++){
            if ((((i-1)*d%P+d)%P*(i-1)%P)>m*2%P){
                cout<<i-1<<endl;
                break;
            }
        }
        return 0;
    }
    sort(a+1,a+n+1);
    for (int l=1;l<=n;l++){
        for (int r=l;r<=n;r++){
            int cnt=0;
            cnt=(P+((r-l+1)%P*a[r])%P-(pre[r]-pre[l-1])%P)%P;
            if (cnt<=m){
                ans=max(ans,r-l+1);
            }
        }
    }
    cout<<ans;
    return 0;
}
