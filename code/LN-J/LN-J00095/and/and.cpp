#include <bits/stdc++.h>
#define int long long
using namespace std;
int m,n,a[200005];
int dfs(int t){
    int ans=-1;
    if(t==0)return LONG_MAX;
    //int t=1;
    for(int i=1;i<=n;i++){
        ans=max(ans,dfs(t-1)&a[i]);
    }
    return ans;
}
signed main()
{ int ans=-1;
    freopen("and2.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    //cout<<f(64)-1<<endl;
    //sort(a+1,a+n+1);
    cout<<dfs(m)<<endl;
    return 0;
}
