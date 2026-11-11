#include <bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long x[2000005];
unsigned long long ans;

int h[305],to[90005],nx[90005],et=2;
int vis[305];
bool cut[305];
int layer[305];
bool in_queue[305];

inline void add_edge(int u,int v){
    to[et]=v;
    nx[et]=h[u];
    h[u]=et++;   
}

const char space=' ';

int bfs(int s){
    memset(vis,0x00,sizeof(vis));
    memset(cut,0x00,sizeof(cut));
    memset(layer,0x3f,sizeof(layer));
    queue<int> q;
    vis[s]=1;
    layer[s]=1;
    q.push(s);
    in_queue[s]=true;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        in_queue[top]=false;
        //cout<<"node:"<<top<<space<<h[top]<<endl;
        for(int i=h[top];i;i=nx[i]){
            int v=to[i];
            //cout<<v<<space<<cut[v]<<space<<layer[v]<<space<<in_queue[v]<<endl;
            if(!cut[v]){
                if(layer[v]>layer[top]+1){
                    layer[v]=layer[top]+1;
                }
                if(layer[v]==layer[top]+1){
                    vis[v]+=vis[top];
                    //if(vis[v]>2) cut[v]=true;
                    //else 
                    if (!in_queue[v]){
                        q.push(v);
                        in_queue[v]=true;
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        //cout<<"vis:"<<vis[i]<<endl;
        if(vis[i]==2) ans++;
    }
    return ans;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(c<=6){
            memset(h,0x00,sizeof(h));
            memset(nx,0x00,sizeof(h));
            memset(to,0x00,sizeof(h));
            et=2;
            int ans=0;
            for(int i=1;i<=n;i++){
                int far=upper_bound(x+1,x+n+1,x[i]+d)-x;
                //cout<<"far"<< i<<space<<far<<endl;
                for(int j=i+1;j<far;j++){
                    add_edge(i,j);
                }
            }
            for(int i=1;i<=n;i++){
                ans+=bfs(i);
            }
            cout<<ans<<'\n';
        }
        else if(11<=c<=12){
            if(x[3]-x[1]<=d && x[4]-x[1]>d){
                cout<<n-3<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }
    return 0;
}