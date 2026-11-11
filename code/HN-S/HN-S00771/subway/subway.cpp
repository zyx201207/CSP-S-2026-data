#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long c,n,m,d,q;
long long w[N];
long long val[501][501];
bool f[501];
long long ans;
vector<long long>v[501];
vector<long long>id[501];
long long value[10001][10001];
long long t[100001][501];
void dfs(long long x,long long res,long long ed){
    if(res>=ans)return;
    if(x==ed){
        ans=min(ans,res);
        return;
    }
    for(long long i=0;i<v[x].size();i++){
        long long son=v[x][i];
        if(f[son])continue;
        f[son]=1;
        dfs(son,res+val[x][son],ed);
        f[son]=0;
    }
}
void dfs1(long long x,long long res,long long ed){
    if(res>=ans)return;
    for(long long i=0;i<id[ed].size();i++)if(id[ed][i]==x){
        ans=min(ans,res+t[x][ed]);
        return;
    }
    sort(v[x].begin(),v[x].end());
    long long tot=unique(v[x].begin(),v[x].end())-v[x].begin()-1;
    for(long long i=0;i<=tot;i++){
        long long son=v[x][i];
        if(f[son])continue;
        f[son]=1;
        if(x)
        dfs1(son,res+value[x][son],ed);
        f[son]=0;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    if(c>=7&&c<=11){
        for(long long i=1;i<=m;i++)cin>>w[i];
        for(long long i=1;i<=n;i++){
            long long k;
            cin>>k;
            if(k==1){
                long long x,val;
                cin>>x>>val;
                continue;
            }
            long long x,valx,y,valy;
            cin>>x>>valx>>y>>valy;
            v[x].push_back(y);
            v[y].push_back(x);
            val[x][y]=valx+valy;
            val[y][x]=valx+valy;
        }
        while(q--){
            ans=1e18;
            long long x,y;
            cin>>x>>y;
            f[x]=1;
            dfs(x,0,y);
            cout<<ans+w[x]+w[y]<<endl;
        }
    }
    memset(value,0x3f,sizeof value);
    for(long long i=1;i<=m;i++)cin>>w[i];
    for(long long i=1;i<=n;i++){
        long long k;
        cin>>k;
        for(long long j=1;j<=k;j++){
            long long x;
            cin>>x;
            cin>>t[i][x];
            for(long long s=0;s<id[x].size();s++){
                v[i].push_back(id[x][s]);
                v[id[x][s]].push_back(i);
                value[i][id[x][s]]=min(value[i][id[x][s]],t[i][x]+t[id[x][s]][x]);
                value[id[x][s]][i]=min(value[id[x][s]][i],t[i][x]+t[id[x][s]][x]);
            }
            id[x].push_back(i);
        }
    }
    while(q--){
        ans=1e18;
        long long x,y;
        cin>>x>>y;
        for(long long i=0;i<id[x].size();i++){
            f[id[x][i]]=1;
            dfs1(id[x][i],t[id[x][i]][x],y);
            f[id[x][i]]=0;
            //cout<<ans<<" "<<t[id[x][i]][x]<<endl;
        }
        cout<<ans+w[x]+w[y]<<endl;
        //cout<<ans<<endl;
    }
    return 0;
}