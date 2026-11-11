#include<iostream>
#include<set>
#include<queue>
using namespace std;
const int RT=1;
const int MAXN=100001;
set<int> s;
void solve(){
    vector<int> g[100001];
    int n=0,k=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int u=0,v=0;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs=[&](auto self,int dep)->void{
        if(dep==k){

            return;
        }
        for(int i:s){
            for(int j:g[i]){
                if(!s.count(j)){
                    s.insert(j);
                }
                self(self,dep+1);
            }
        }
    };
}
void cheat(){
    vector<int> g[100001];
    int f[100001]={};
    int dep[100001]={};
    int maxdep=0;
    bool vis[100001]={};
    //cout<<"-\n";
    struct node{
        int id;
        int step;
        node(int a,int b){
            id=a;
            step=b;
        }
    };
    int n=0,k=0;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u=0,v=0;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int left=n-1;
    vis[RT]=true;
    queue<node> q;
    q.push(node(RT,1));
    dep[RT]=1;
    auto dfs2=[&](auto self,int u,int fa)->void{
        f[u]=fa;
        bool isleaf=true;
        for(int v:g[u]){
            if(v!=fa){
                isleaf=false;
                dep[v]=dep[u]+1;
                maxdep=max(maxdep,dep[v]);
                self(self,v,u);
            }
        }
        if(isleaf){
            q.push(node(u,1));
            left--;
            vis[u]=true;
        }
    };
    dfs2(dfs2,RT,RT);
    while(!q.empty()){
        node u=q.front();
        q.pop();
        //cout<<g[u.id].size();
        if(left<=k){
            cout<<u.step<<"\n";
            return;
        }
        for(int v:g[u.id]){
            if(!vis[v]){
                //cout<<"pushed!\n";
                q.push(node(v,u.step+1));
                left--;
                vis[v]=true;
                if(left<=k){
                    cout<<u.step+1<<"\n";
                    return;
                }
            }
        }
        //cout<<n<<" "<<left<<endl;
    }
    //cout<<"END\n";
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c=0,t=0;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cheat();
    }
    return 0;
}
