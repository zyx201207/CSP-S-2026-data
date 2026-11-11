#include<algorithm>
#include<iostream>
#include<iterator>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<ctime>
#include<cmath>
#include<set>
#include<map>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

struct node{
    int m_u;
    int m_w;

    node(int _U=0,int _W=0){
        m_u=_U;
        m_w=_W;
    }
};

struct node_{
    int m_len;
    int m_tim[55]; //zhan ting
    int m_stat[55]; //zhan
};

int u,v;
int vis[505];
int c,d,n,m,Q;
int W[500005];
int x_p[505][505];
node_ xter[500005];
vector<node> arr[505];
priority_queue<PII,vector<PII>,greater<PII> > q;

void add(int _u,int _v,int _w){
    arr[_u].push_back(node(_v,_w));
    arr[_v].push_back(node(_u,_w));
}

void dijkstra(int s){
    int u,v,w;
    while(!q.empty()){
        q.pop();
    }
    memset(vis,0,sizeof(vis));
    q.push(make_pair(0,s));
    x_p[s][s]=0;
    while(!q.empty()){
        u=q.top().second;
        q.pop();
        if(vis[u]){
            break;
        }
        vis[u]=1;
        for(int i=0;i<arr[u].size();i++){
            v=arr[u][i].m_u;
            w=arr[u][i].m_w;
            if(x_p[s][u]+w<x_p[s][v]){
                x_p[s][v]=x_p[s][u]+w;
                q.push(make_pair(x_p[s][v],v));
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
    for(int i=1;i<=m;i++){
        scanf("%d",W+i);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&xter[i].m_len);
        for(int j=1;j<=xter[i].m_len;j++){
            scanf("%d%d",&xter[i].m_stat[j],&xter[i].m_tim[j]);
        }
        for(int j=1;j<=xter[i].m_len;j++){
            for(int k=j+1;k<=xter[i].m_len;k++){
                add(xter[i].m_stat[j],xter[i].m_stat[k],xter[i].m_tim[j]+xter[i].m_tim[k]);
            }
        }
    }
    memset(x_p,0x3f,sizeof(x_p));
    for(int i=1;i<=n;i++){
        dijkstra(i);
    }
    while(Q--){
        scanf("%d%d",&u,&v);
        printf("%d\n",x_p[u][v]+W[u]+W[v]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
