#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2*1e6+10;

int C,T;
int n,k;
vector<int> g[N];
int vis[N];
int dis[N];
int ans=0x3f3f3f3f;

void dfs2(int u,int f){
    for(auto v:g[u]){
        if(v==f)continue;
        dis[v]=dis[u]+1;
        dfs2(v,u);
    }
}

void dfs1(int x){
    if(x==n+1){
        bool vis1[n+10];
        for(int i=1;i<=n;i++){
            vis1[i]=false;
        }
        vector<int> v1;
        vector<int> v2;
        for(int i=1;i<=n;i++){
            if(vis[i]==1){
                v1.push_back(i);
            }
            if(vis[i]==2){
                v2.push_back(i);
            }
        }
        if(v1.size()+v2.size()!=k){
            return;
        }
        bool boo=true;
        if(v1.size()!=0){
            for(int i=0;i<v1.size();i++){
                for(int j=0;j<g[v1[i]].size();j++){
                    vis1[g[i][j]]=true;
                }
            }
            for(int i=0;i<v1.size();i++){
                if(vis1[v1[i]]==false){
                    boo=false;
                    break;
                }
            }


//            queue<int> q1;
//            q1.push(v1[0]);
//            int cnt1=0;
//            vis1[v1[0]]=true;
//            while(!q1.empty()){
//                int u=q1.front();
//                q1.pop();
//                for(auto v:g[u]){
//                    if(vis1[v]==false&&vis[v]==1){
//                        cnt1++;
//                        q1.push(v);
//                        vis1[v]=true;
//                    }
//                }
            }
//            for(auto ppp:v1){
//                cout<<ppp<<" ";
//            }cout<<endl;
//            if(cnt1!=v1.size()){
////                cout<<cnt1<<"    *******88888888888888887&&&&&&*\n";
//                boo=false;
//            }

        if(v2.size()!=0){
                for(int i=0;i<v2.size();i++){
                for(int j=0;j<g[v2[i]].size();j++){
                    vis1[g[i][j]]=true;
                }
            }
            for(int i=0;i<v2.size();i++){
                if(vis1[v2[i]]==false){
                    boo=false;
                    break;
                }
            }
//            queue<int> q2;
//            q2.push(v2[0]);
//            int cnt2=0;
//            vis1[v2[0]]=true;
//            while(!q2.empty()){
//                int u=q2.front();
//                q2.pop();
//                for(auto v:g[u]){
//                    if(vis1[v]==false&&vis[v]==2){
//
//                        cnt2++;
//                        q2.push(v);
//                        vis1[v]=true;
//                    }
//                }
//            }
//            C
//            if(cnt2!=v2.size()){
////                    cout<<"*******&7&&&&&&*\n";
//                boo=false;
//            }
        }
        if(boo==true){
            int aans=0LL;
            for(int i=1;i<=n;i++){
                if(vis[i]==2||vis[i]==3)continue;
                for(int i=1;i<=n;i++){
                    vis1[i]=false;
                }
                queue<pair<int,int>> q;
                q.push({i,0});
                int mi=0x3f3f3f3f;
                while(!q.empty()){
                    int u=q.front().first;
                    int step=q.front().second;
                    q.pop();
                    if(vis[u]==1||vis[u]==2){
                        mi=step;
                        break;
                    }
                    for(auto v:g[u]){
                        if(vis1[v]==false){
                            q.push({v,step+1});
                            vis1[v]=true;
                        }
                    }
                }
                aans=max(aans,mi);
            }
            ans=min(aans,ans);
        }
        return;
    }
    vis[x]=0;
    dfs1(x+1);
    vis[x]=1;
    dfs1(x+1);
    vis[x]=2;
    dfs1(x+1);
}


void solve1(){
    while(T--){
        for(int i=1;i<=n;i++){
            g[i].clear();
            vis[i]=0;
        }
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs2(1,0);
        dfs1(1);
        cout<<ans<<endl;
    }
}

void solve2(){
    while(T--){
        for(int i=1;i<=n;i++){
            g[i].clear();
            vis[i]=0;
        }
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs2(1,0);
        dfs1(1);
        cout<<ans<<endl;
    }
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>C>>T;
    if(C<=3){
        solve1();
    }
    if(C==7||C==11||C==12){
        solve2();
    }
    return 0;
}
