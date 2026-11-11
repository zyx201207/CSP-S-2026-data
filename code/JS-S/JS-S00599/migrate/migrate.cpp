#include<bits/stdc++.h>
using namespace std;

#define int long long

int C,T;

int n,d;
int x[2000010],l[2000010],r[2000010];
vector<int>e[5010];
struct State{
    int x,y;
};
queue<State>q;
int dis[5010],cnt[5010],vis[5010];

void bfs(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
    cnt[s]=1,dis[s]=0;
    while(q.size())q.pop();
    q.push({s,0});
    while(q.size()){
        State t=q.front();
        q.pop();
        cnt[t.x]+=cnt[t.y];
        if(vis[t.x]==0){
            vis[t.x]=1;
        }
        else{
            continue;
        }
        for(auto i:e[t.x]){
            if(dis[i]>=dis[t.x]+1){
                dis[i]=dis[t.x]+1;
                q.push({i,t.x});
            }
        }
    }
}

void clear(){
    if(C<=6){
        for(int i=1;i<=n;++i){
            e[i].clear();
        }
    }
}

void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;++i){
        cin>>x[i];
    }
    for(int p=1,i=1;i<=n;++i){
        while(x[i]-x[p]>d){
            p++;
        }
        l[i]=p;
    }
    for(int p=n,i=n;i>=1;--i){
        while(x[p]-x[i]>d){
            p--;
        }
        r[i]=p;
    }
    if(C<=6){
        int ans=0;
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=r[i];++j){
                e[i].push_back(j);
                e[j].push_back(i);
            }
        }
        for(int i=1;i<=n;++i){
            bfs(i);
            for(int j=i+1;j<=n;++j){
                if(cnt[j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    else if(C==13||C==14){
        vector<int>v;
        for(int i=1;i<=n;++i){
            if(l[i]==1&&r[i]==n){
                v.push_back(i);
            }
        }
        int ans=0;
        if(v.size()==1){
            for(int i=1;i<=n;++i){
                if(r[i]==v[0]+1){
                    ans+=(n-r[i]);
                }
            }
            cout<<ans<<"\n";
        }
        else if(v.size()==2){
            for(int i=1;i<=n;++i){
                if(r[i]==v[1]){
                    ans+=(n-r[i]);
                }
            }
            cout<<ans<<"\n";
        }
        else{
            cout<<0<<"\n";
        }
    }
    else{
        cout<<0<<"\n";
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
        clear();
        solve();
    }
}