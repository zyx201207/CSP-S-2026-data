#include <bits/stdc++.h>
using namespace std;
#define N 500007
#define int long long
#define ll __int128
ll a[N];
ll b[N];
int n,M;
ll m;


signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>M;
    m=M;
    for(int i=1,x;i<=n;++i){
        cin>>x;
        a[i]=x;
    }
    sort(a+1,a+n+1);
    for(int j=1;j<=n;++j){
        b[j]=b[j-1]+a[j];
    }
    int i=1,j=1;
    int ans=0;
    while(j<=n){
        while(i<j&&a[j]*(j-i+1)-(b[j]-b[i-1])>m){
            ++i;
        }
        if(a[j]*(j-i+1)-(b[j]-b[i-1])<=m){
            ans=max(ans,j-i+1);
        }
        //cout<<i<<' '<<j<<'\n';
        ++j;
    }
    cout<<ans<<'\n';
}