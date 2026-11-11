#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> edge[1000005],v;
int n,k;
bool flag[1000005];
bool f[1000005];
int dis[10005][10005];

void bfs(int x){
    queue<int> q;
    q.push(x);
    f[x]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i:edge[u]){
            if(flag[i]&&!f[i]){
                q.push(i);
                f[i]=true;
            }
        }
    }
    return;
}

bool cntfun(){
    int cnt=0;
    memset(f,false,sizeof(false));
    for(int i:v){
        if(!f[i]){
            cnt++;
            if(cnt>2){
                return false;
            }
            bfs(i);
        }
    }
    if(cnt<=2){
        return true;
    }
    return false;
}

int ans=100000005;

void dfs(int x){
    if(x==k){
        if(cntfun()){
            int t=0;
            for(int i=1;i<=n;i++){
                int temp=100000005;
                for(int x:v){
                    temp=min(temp,dis[x][i]);
                }
                t=max(t,temp);
            }
        ans=min(ans,t);
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!flag[i]){
            v.push_back(i);
            flag[i]=true;
            dfs(x+1);
            flag[i]=false;
            v.pop_back();
        }
    }
    return;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            int x,y;
            cin>>x>>y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        for(int i=1;i<=n;i++){
            queue<int> q;
            q.push(i);
            bool flag[1000005]={false};
            flag[i]=true;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(int x:edge[u]){
                    if(!flag[x]){
                        dis[i][x]=dis[i][u]+1;
                        flag[x]=true;
                        q.push(x);
                    }
                }
            }
        }
        memset(flag,false,sizeof(flag));
        ans=1000000005;
        dfs(0);
        cout << ans<<endl;
    }
    return 0;
}
