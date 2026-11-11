#include <bits/stdc++.h>
#define int long long

using namespace std;

namespace annika{
    const int N=5e5+3;
    int n,m,a[N],s[N],ans;

    void main(){
        cin>>n>>m;
        for (int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        for (int i=1;i<=n;i++){
            s[i]=s[i-1]+a[i];
            int l=1,r=i,tmp;
            while (l<=r){
                int mid=(l+r)>>1;
                if ((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m){
                    tmp=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            ans=max(ans,i-tmp+1);
        } 
        cout<<ans;
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    annika::main();

    return 0;
}