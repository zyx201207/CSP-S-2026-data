#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],cf[500004],tmp,ans,cnt,cnt2;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(n<=5000){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        for(int i=n;i>=2;i--){
            tmp=0,cnt=0,cnt2=1;memset(cf,0,sizeof(cf));
            for(int j=1;j<=i-1;j++){
                cf[++cnt]=a[i]-a[j];
            }
            for(int j=cnt;j>=1;j--){
                if(tmp+cf[j]<=m){
                    tmp+=cf[j];cnt2++;
                }
                else break;
            }
            ans=max(cnt2,ans);
        }
        cout<<ans;
        return 0;
    }
    else {
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        for(int i=n;i>=2;i--){
            if(a[i]*(n-1)-(a[1]+a[n-1])*(n-1)/2<=m){
                cout<<a[i]*(n-1)-(a[1]+a[n-1])*(n-1)/2;
                return 0;
            }
        }
    }
    return 0;
}