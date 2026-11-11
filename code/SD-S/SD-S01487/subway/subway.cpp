#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e7+10;
const int M=1010;
const int inf=1e18+10;
struct tt{
	int u,v,w,nxt;
}e[N];
struct hh{
	int v1,w1;
	bool operator < (const hh &x)const{
		return w1>x.w1;
	}
};
int c,n,m,d,Q;
int W[N],k[M],uu[N],vv[N],ww[N],h[N],cnt,tot;
int dis[N],vis[N];
vector<int>a[M];
vector<int>t[M];
priority_queue<hh>q;
void add(int u,int v,int w){
	e[++tot].u=u;
	e[tot].v=v;
	e[tot].w=w;
	e[tot].nxt=h[u];
	h[u]=tot;
}
void diji(int s){
	for(int i=1;i<=m;i++)dis[i]=inf,vis[i]=0;
	dis[s]=0;
	q.push({s,dis[s]});
	while(!q.empty()){
		hh now=q.top();
		int u=now.v1;
		q.pop();
		//cout<<u<<"\n";
		if(vis[u])continue;
		vis[u]=1;
		for(int i=h[u];i!=-1;i=e[i].nxt){
			int v=e[i].v,w=e[i].w;
			//cout<<v<<" "<<w<<"\n";
			//cout<<dis[v]<<"\n";
			dis[v]=min(dis[v],dis[u]+w);
			//cout<<dis[u]<<" "<<dis[v]<<"\n";
			q.push({v,dis[v]});
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(h,-1,sizeof h);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,tt;
			cin>>x>>tt;
			a[i].push_back(x);
			t[i].push_back(tt);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			for(int l=0;l<k[i];l++){
				if(l==j)continue;
				cnt++;
				uu[cnt]=a[i][j],vv[cnt]=a[i][l];
				ww[cnt]=t[i][j]+t[i][l]; 
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		int u=uu[i],v=vv[i],w=ww[i];
		add(u,v,w);
	}
//	for(int i=1;i<=tot;i++){
//		cout<<"i,u,v,w,nxt:"<<"\n";
//		cout<<i<<" "<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<" "<<e[i].nxt<<"\n";
//	}
	//diji(1);
	while(Q--){
		int x,y;
		cin>>x>>y;
		diji(x);
		cout<<W[x]+W[y]+dis[y]<<"\n";
	}
	return 0;
}

