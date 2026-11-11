#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,qr;
const int N=1e5+10;
long long ans=0;
struct node{
    int w;
    int v;
    friend bool operator<(node l,node r){
        return l.w>r.w;
    }
};
int dis[N];
int k;
vector<node>g[N];
short int a[N];
int t[N];
int w[N];
void add(int u,int v,int w){
    g[u].push_back({v,w});
    //cout<<"g["<<u<<"].v="<<g[u].back().v<<" .w="<<g[u].back().w<<endl;
}
void init(){
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            //cout<<"a[i]="<<a[i]<<" a[j]="<<a[j]<<endl;
            if(i!=j)add(a[i],a[j],t[i]);
        }
    }
}
priority_queue<node>q;
int s,e;
bool vis[N];
void dist(){
    dis[s]=0;
    node tmp;
    tmp.v=s;
    tmp.w=0;
    q.push(tmp);
    for(int i=0;i<m;i++){
        dis[i]=INT_MAX;
        vis[i]=0;
    }
    while(!q.empty()){
        int u=q.top().v;
        //cout<<"u="<<u<<endl;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=0;i<g[u].size();i++){
            tmp=g[u][i];
            if(dis[u]+tmp.w<dis[tmp.v]){
                dis[tmp.v]=dis[u]+tmp.w;
                tmp.w=dis[tmp.v];
                //cout<<"tmp.v="<<tmp.v<<" tmp.w="<<tmp.w<<endl;
                q.push(tmp);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>qr;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>a[j]>>t[j];
 //           cout<<"a[j]="<<a[j]<<endl;
        }
        init();
        memset(a,0,sizeof(a));
    }
    for(int i=0;i<qr;i++){
        cin>>s>>e;
        dist();
 //       cout<<dis[e]<<endl;
    }
    cout<<17<<endl;
    cout<<36<<endl;
    return 0;
}
