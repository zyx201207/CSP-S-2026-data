#include<bits/stdc++.h>
#define PI pair<int,int>
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
vector<PI>a[200001];//zhanting
vector<PI>b[501];//zhantai
int w[200001];//ditiekou->zhanting
int h1[200001],h2[501],n;
struct node{
    int id;
    int w;
    int f;//f:0->zhanting  1->zhantai
    int fa;
};
queue<node>q;
void work(int U,int V){
    int u,v,vw,w,f,fa;
    q.push(node{U,0,0,0});
    while(!q.empty()){
        u=q.front().id;w=q.front().w;f=q.front().f;fa=q.front().fa;
        q.pop();
//        cout<<u<<" "<<w<<" "<<f<<" "<<fa<<"\n";
        if(!f){
            if(h1[u]<=w) continue;
            h1[u]=w;
            for(int i=0;i<a[u].size();i++){
                v=a[u][i].first;vw=a[u][i].second;
               if(h2[v]<vw+w || fa==v) continue;
               q.push(node{v,vw+w,1,u});
            }
        }
        else{
            if(h2[u]<=w) continue;
            h2[u]=w;
            for(int i=0;i<b[u].size();i++){
                v=b[u][i].first;vw=b[u][i].second;
                if(h1[v]<vw+w || fa==v) continue;
                q.push(node{v,vw+w,0,u});
            }
        }

    }
    return ;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,m,d,p,x,u,v,t;
    c=read(),n=read(),m=read(),d=read(),p=read();
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1;i<=n;i++){
        x=read();
        for(int j=1;j<=x;j++){
            v=read();t=read();
            b[i].push_back(make_pair(v,t));
            a[v].push_back(make_pair(i,t));
        }
    }
    for(int i=1;i<=p;i++){
        u=read();v=read();
        for(int j=1;j<=n;j++) h2[j]=INT_MAX;
        for(int j=1;j<=m;j++) h1[j]=INT_MAX;
        work(u,v);
//        for(int j=1;j<=m;j++) cout<<h1[j]<<" ";
//        cout<<endl;
        cout<<w[u]+h1[v]+w[v]<<'\n';
    }
    return 0;
}
//haisheng25min..
//wananmakabaka