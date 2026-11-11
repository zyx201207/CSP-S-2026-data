#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],ans=-1;
void dfs(int j,int cnt,int step){
    if(step==m){
        ans=max(ans,cnt);
        return;
    }
    if(j>=n) return;
    dfs(j+1,cnt&a[j],step+1);
    dfs(j+1,cnt,step);
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n-m;i++)
        dfs(i,a[i],0);
    cout<<ans;
    return 0;
}
