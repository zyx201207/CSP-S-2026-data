#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int c,t,n,k,ans;
vector<int>g[2222222],le[222222];
struct node{
    int x,step;
};
bool b[111];
int calc(vector<int>v){
    int sum=0,dis[111],cnt;
    for(int i=1;i<=n;i++){
        queue<node>q;
        for(int j=0;j<v.size();j++){
            cnt=inf;
            while(!q.empty()){
                q.pop();
            }
            memset(dis,0x3f,sizeof(dis));
            q.push({v[j],0});
            dis[v[j]]=0;
            while(!q.empty()){
                int x=q.front().x,step=q.front().step;
                q.pop();
                for(int l=0;l<g[x].size();l++){
                    int nx=g[x][l];
                    if(dis[nx]>step+1){
                        dis[nx]=step+1;
                        q.push({nx,dis[nx]});
                    }
                }
            }
            cnt=min(cnt,dis[i]);
        }
        sum=max(sum,cnt);
    }
    return sum;
}
void liantongkuai(int x){
    for(int i=0;i<le[x].size();i++){
        if(b[le[x][i]]==0){
            b[le[x][i]]=1;
            liantongkuai(le[x][i]);
        }
    }
}
bool check(vector<int>v){
    int sum=0;
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++){
        le[i].clear();
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<g[i].size();j++){
            bool f1=0,f2=0;
            for(int l=0;l<v.size();l++){
                if(v[l]==i)
                    f1=1;
                if(g[i][j]==v[l])
                    f2=1;
            }
            if(f1==1 and f2==1){
                le[i].push_back(g[i][j]);
                le[g[i][j]].push_back(i);
            }
        }
    }
    for(int i=0;i<v.size();i++){
        if(!b[v[i]]){
            sum++;
            liantongkuai(v[i]);
        }
        if(sum>=3)
            return 0;
    }
    return 1;
}
void dfs(int x,int step,vector<int>v){
    if(x==k){
        if(check(v))
            ans=min(ans,calc(v));
        return;
    }
    if(step==n+1)
        return;
    v.push_back(step);
    dfs(x+1,step+1,v);
    v.pop_back();
    dfs(x,step+1,v);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=inf;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int>v;
        v.clear();
        dfs(0,1,v);
        cout<<ans<<endl;
    }
}
