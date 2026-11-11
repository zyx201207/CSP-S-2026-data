#include<bits/stdc++.h>
using namespace std;
bool vis[15],tar[15],used[15];
void init(vector<int>c){
    memset(tar,0,sizeof(tar));
    for(int i=0;i<c.size();i++){
        tar[c[i]]=1;
    }
}
int bfs(vector<int>t[15],int x){
    memset(vis,0,sizeof(vis));
    vis[x]=1;
    vector<int>d(15);
    queue<int>q;
    q.push(x);
    d[x]=0;
    while(q.size()){
        int u=q.front();
        q.pop();
        if(tar[u])return d[u];
        for(int i=0;i<t[u].size();i++){
            if(!vis[i]){
                q.push(i);
                d[i]=d[u]+1;
                vis[i]=1;
            }
        }
    }
}
bool chk(vector<int>t[15],vector<int>c){
    memset(vis,0,sizeof(vis));
    memset(used,0,sizeof(used));
    memset(tar,0,sizeof(tar));
    for(int i=0;i<c.size();i++){
        tar[c[i]]=1;
    }
    int x=c[0];
    vis[x]=1;
    queue<int>q;
    q.push(x);
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=0;i<t[u].size();i++){
            if(!vis[i]&&tar[i]){
                q.push(i);
                vis[i]=1;
            }
        }
    }
    int s=-1;
    for(int i=0;i<c.size();i++){
        if(vis[c[i]]==0){
            s=i;
            break;
        }
    }
    if(s==-1){
        return true;
    }
    vis[s]=1;
    queue<int>Q;
    Q.push(s);
    while(Q.size()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<t[u].size();i++){
            if(!vis[i]&&tar[i]){
                Q.push(i);
                vis[i]=1;
            }
        }
    }
    for(int i=0;i<c.size();i++){
        if(vis[c[i]]==0)return false;
    }
    return true;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    c=3;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>t[15];
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            t[x].push_back(y);
            t[y].push_back(x);
        }
        if(c<=3){
            int ans=1e9;
            for(int i=0;(1<<n);i++){
                vector<int>c;
                for(int j=0;j<n;j++){
                    if(i>>j&1){
                        c.push_back(j+1);
                    }
                }
                if(c.size()!=k){
                    continue;
                }
                if(chk(t,c)){
                    int res=0;
                    for(int i=1;i<=n;i++){
                        init(c);
                        res=max(res,bfs(t,i));
                    }
                    ans=min(ans,res);
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
