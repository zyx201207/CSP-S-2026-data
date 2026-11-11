#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+5;
int c,n,m,d,q,x,y;
map<pair<int,int>,long long> v;
map<int,vector<pair<int,long long>>> m1;
long long w[maxn],sum,ans;
bool vis[maxn];
void dfs(int a){
    vis[a]=1;
    bool f=0;
    for(auto x1:m1[y]){
        if(a==x1.first){
            f=1;
            ans=min(ans,sum+x1.second);
        }
    }
    if(f) return;
    for(int i=1;i<=n;i++){
        if(vis[i]==0&&v.find({min(i,a),max(i,a)})!=v.end()){
            sum+=v[{min(i,a),max(i,a)}];
            dfs(i);
            sum-=v[{min(i,a),max(i,a)}];
        }
    }
    vis[a]=0;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    long long k,a,t;
    for(int i=1;i<=n;i++){
        cin>>k;
        while(k--){
            cin>>a>>t;
            for(auto x1:m1[a]){
                v[{x1.first,a}]=min(x1.second+t,v[{x1.first,a}]);
            }
            m1[a].push_back({i,t});
        }
    }
    while(q--){
        cin>>x>>y;
        ans=1e18;sum=0;
        for(int i=1;i<=n;i++) vis[i]=0;
        dfs(x);
        cout<<ans+w[x]+w[y]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
