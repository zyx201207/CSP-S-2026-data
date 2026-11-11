#include<bits\stdc++.h>
using namespace std;
const int N=5e5+5;
int n,c,m,d,q,w[N],k[N],head[N],tot,ver[N],ew[N],nxt[N],dis[N],x,y;
bool vis[N];
void add(int u,int v,int ww){
	tot++;
	ver[tot]=v;
	ew[tot]=ww;
	nxt[tot]=head[u];
	head[u]=tot;
}
void spfa(){
	queue<int>qq;
	qq.push(x);
	vis[x]=1;
	while(!qq.empty()){
		int t=qq.front();
		if(!vis[t]){
			vis[t]=1;
			for(int i=head[t];i!=-1;i=nxt[i]){
				if(dis[ver[i]]>dis[t]+w[i]){
					dis[ver[i]]=dis[t]+w[i];
					qq.push(i);
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int dot,t,dott=0;
		for(int j=1;j<=k[i];j++){
			cin>>dot>>t;
			add(j,dot,t);
			add(dot,j,t);
		}
	}
	spfa();
	while(q--){
		cin>>x>>y;
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
