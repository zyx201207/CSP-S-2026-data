#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=1e9;
int n,m,a[N],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1,j=1,s=0;i<=n;++i){
        while(s>m)
            s-=a[i]-a[j++];
        ans=max(ans,i-j+1);
        s+=(a[i+1]-a[i])*(i-j+1);
    }
    cout<<ans<<'\n';
    return 0;
}