#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<map>
#include<utility>
using namespace std;

const int MAXM=5e5*23+5;

struct Edge{
  int to,nxt,val;
  Edge(int a,int b,int c){to=a,nxt=b,val=c;}
};
struct Node{
  int i,w;
  Node(int a,int b){i=a,w=b;}
  friend bool operator<(const Node &a,const Node &b){
    return a.w>b.w;
  }
};
int c,n,m,d,q;
int h[MAXM],dis[MAXM];
// vector<int>  h;
//vector<int>  dis;
vector<Edge> e;
map<pair<int,int>,int> hist;


// i                  -> entrance
// i+m                -> hall
// i+2*m+20*(i-1)+j   -> route


void add_single_edge(int u,int v,int w){
  e.push_back(Edge(v,h[u],w));
  h[u]=e.size()-1;
}

void addedge(int u,int v,int w){
  add_single_edge(u,v,w);
  add_single_edge(v,u,w);
}


int dijkstra(int x,int y){
  if(hist[make_pair(x,y)]) return hist[make_pair(x,y)];
  if(hist[make_pair(y,x)]) return hist[make_pair(y,x)];
  priority_queue<Node> q;
  memset(dis,0x3f,sizeof dis);
  dis[0]=dis[x]=0;
  q.push(Node(x,0));
  //printf("Added node x=%d to queue.\n",x);
  while(!q.empty()){
    Node cur=q.top(); q.pop();
    if(cur.w!=dis[cur.i]) continue;
    int u=cur.i;
    //printf("  Relaxing node %d...\n",u);
    for(int i=h[u];i;i=e[i].nxt){
      //printf("    Relaxing node %d's edge %d...  [%d --- %d ---> %d]\n",u,i,u,e[i].val,e[i].to);
      int v=e[i].to;
      if(dis[v]>dis[u]+e[i].val){
        dis[v]=dis[u]+e[i].val;
        //puts("      Relaxed successfully!");
        q.push(Node(v,dis[v]));
      }
    }
  }
  hist[make_pair(x,y)]=dis[y];
  return dis[y];
}

int main(){
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
  //h.resize(3*m+10);
  //dis.resize(3*m+10);
  e.push_back(Edge(0,0,0));
  for(int i=1;i<=m;++i){
    int w; scanf("%d",&w);
    addedge(i,i+m,w);
    //rintf("Added an edge from [%d]'s entrance to its hall. w=%d\n",i,w);
  }
  for(int i=1;i<=n;++i){
    //printf("Processing route %d...\n",i);
    int k;   scanf("%d",&k);
    int a,t; scanf("%d%d",&a,&t); addedge(a+m,a+2*m+(a-1)*20+i,t);
    //printf("  Added edge [%d]'s route <-> [%d]'s hall. w=%d\n",a,a,t);
    for(int j=2;j<=k;++j){
      int a1; scanf("%d%d",&a1,&t);
      addedge(a1+m,a1+2*m+(a1-1)*20+i,t);               // hall   -> route
      //printf("  Added edge [%d]'s hall <-> [%d]'s route.  w=%d\n",a1,a1,t);
      addedge(a+2*m+(a-1)*20+i,a1+2*m+(a1-1)*20+i,0);   // route1 -> route2
      //printf("  Added edge [%d]'s route <-> [%d]'s route.\n",a,a1);
      a=a1;
    }
  }
  //puts("All edges added!");
  for(int i=1;i<=q;++i){
    int x,y; scanf("%d%d",&x,&y);
    printf("%d\n",dijkstra(x,y));
  }
  return 0;
}