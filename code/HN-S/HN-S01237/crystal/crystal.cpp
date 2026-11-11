#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+7;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
int n,m,a[maxn],b[maxn];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    int ans=1,lcur=1;
    for(int i=2;i<=n;i++){
        while(m<a[i]*(i-lcur+1)-(b[i]-b[lcur-1])) lcur++;
        ans=max(ans,i-lcur+1);
    }
    cout<<ans;
    return 0;
}
// the end of hope.