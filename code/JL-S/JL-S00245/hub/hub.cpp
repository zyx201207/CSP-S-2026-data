#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
vector<int>a[200005];
int n,k;
int ans=0;
bool f[100005];
void dfs(int sum,int y,int fa){
    ans=max(ans,sum);
    if(fa==k){
        return;
    }
    for(int i=0;i<a[fa].size();i++){
        if(f[a[fa][i]]==0){
            dfs(sum+1,y+1,a[fa][i]);
            f[a[fa][i]]==0;
        }
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            a[u].push_back(v);
            a[u].push_back(v);
        }
        int r=0;
        for(int i=1;i<=n;i++){
            dfs(0,1,i);
            r=min(ans,r);
            ans=0;
        }
        cout<<r;
        for(int i=1;i<=n;i++){
            a[i].clear();
            f[i]=0;
        }
    }
    return 0;
}

