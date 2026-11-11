#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m,ans;
int a[N],s[N],f[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(a[1]<0){
        for(int i=1;i<=n;i++) a[i]+=a[1];
    }
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    int l=1,r=2;
    while(l<=r&&r<=n){
        int d=(r-l)*a[r]-(s[r-1]-s[l-1]);
        if(d<=m) r++;
        else if(d>m){
            l++;
            ans=max(ans,r-l+1);
        }
    }
    cout<<ans;
    return 0;
}
