#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int now=0,ans=0,nmx=0;
int a[500050],d[500050];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)d[i]=d[i-1]+a[i];
    int i=1,j=1;
    while(i<=n&&j<=n){
        now=a[j]*(j-i+1)-(d[j]-d[i-1]);
        if(now<=m){
            ans=max(ans,j-i+1);
            nmx=a[++j];
        }
        else{
            while(now>m){
                i++;
                now=a[j]*(j-i+1)-(d[j]-d[i-1]);
            }
        }
        //cout<<i<<' '<<j<<' '<<ans<<'\n';
    }
    cout<<ans;
}
