#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],n,m;
bool vis[200005];


int dfs(int s,int ans){
    if(s>=m){
        return ans;
    }
    int mmax=0,idx=0;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        if(ans&a[i]>mmax)
            mmax=a[i]&ans,idx=i;
    }
    vis[idx]=1;
    return dfs(s+1,a[idx]&ans);
}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int mmax=0,allans=0x7fffffffffffffff,idx=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mmax=max(mmax,a[i]);
        allans&=a[i];
    }
    for(idx=1;idx<=n;idx*=2);
    cout<<(idx==2*n)<<endl;
    if(m==n){
        cout<<allans<<endl;
        return 0;
    }else if(m==1){
        cout<<mmax<<endl;
        return 0;
    }else if(idx==2*n){
        cout<<m-n<<endl;
        return 0;
    }

    mmax=0;
    for(int i=1;i<=n;i++){
        vis[i]=1;
        mmax=max(mmax,dfs(1,a[i]));
        vis[i]=0;
    }
    cout<<mmax<<endl;
    return 0;
}
