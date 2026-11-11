#include<bits/stdc++.h>
using namespace std;
#define int long long
int mj[200005],ans;
int n;
void dfs(int start,int zhi,int tms){
    if(tms==1){
        ans=max(ans,zhi);
        return;
    }
    for(int i=start;i<=n;i++){
        dfs(i+1,(zhi&mj[i]),tms-1);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n;
    int q;
    cin>>q;
    for(int i=1;i<=n;i++){
        cin>>mj[i];
    }
    for(int i=1;i<=n;i++){
        dfs(i+1,mj[i],q);
    }
    cout<<ans;
    return 0;
}
