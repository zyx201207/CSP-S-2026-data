#include<bits/stdc++.h>
#define ll long long
#define atn 222222
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define f(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
vector<int>v[atn];
int cl[atn];
bool vis[atn];
set<int>vv;
void dfs(int x){
    if(cl[x]==1)return;
    cl[x]=1;
    for(auto y:v[x]){
        if(!vv.count(y))continue;

        dfs(y);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        int n,k,ans=0x3f3f3f3f;
        cin>>n>>k;
        f(i,1,n)v[i].clear();
        f(i,1,n-1){
            int u,V;cin>>u>>V;
            v[u].pb(V);v[V].pb(u);
        }
        f(msk,0,(1<<n)-1){
            if(__builtin_popcount(msk)!=k)continue;
            vv.clear();
            f(i,1,n)if(msk&(1<<(i-1)))vv.insert(i);
            int tt=0;
            f(i,1,n)cl[i]=0;
            for(auto i:vv){
                if(cl[i]==0)dfs(i),++tt;
            }
            if(tt>2)continue;
            int ta=0;
            f(i,1,n){
                queue<pair<int,int>>q;
                q.push({i,0});
                f(j,1,n)vis[j]=0;
                int tans=0;
                while(!q.empty()){
                    int x=q.front().fi,z=q.front().se;
                    q.pop();
                    if(vis[x])continue;
                    else vis[x]=1;
                    if(vv.count(x)){
                        tans=z;break;
                    }
                    for(auto y:v[x]){
                        q.push({y,z+1});
                    }
                }
                ta=max(ta,tans);
            }
            ans=min(ans,ta);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
