#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500009;
int n,m,a[N],s[N],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        for(int l=1,r=i;l<=r;){
            int md=(l+r)>>1;
            if((i-md+1)*a[i]-(s[i]-s[md-1])<=m)ans=max(ans,i-md+1),r=md-1;
            else l=md+1;
        }
    }
    cout<<ans;
}