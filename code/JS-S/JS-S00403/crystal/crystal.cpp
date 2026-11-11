#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],d[N];
int n,m;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ans=1;int l=n;
    int cur=0;
    for(int r=n;r>=1;r--){
        while(true){
            if(l==1) break;
            if(cur+(a[r]-a[l-1])>m) break;
            l--;
            cur+=(a[r]-a[l]);
        }
        ans=max(ans,r-l+1);
        if(l==1) break;
        //cout<<ans<<endl;
        cur=cur-(a[r]-a[r-1])*(r-l);
    }
    cout<<ans<<endl;
    return 0;
}
