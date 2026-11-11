#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
}
int c,n,m,d,q;
const int M=250005;
int w[M],k[505];
vector<pair<int,int> >e[M];
int a[505][405],t[505][405];
map<pair<int,int>,bool>vis;
void addedge(int u,int v,int w){
	e[u].push_back({v,w});
}
int dist[1005][1005];
bool viss[100005];
void spfa(int s){
	for(int i=1;i<=n*m;i++){
		viss[i]=false;
		dist[i][i]=1e18;
	}
	viss[s]=true;
	dist[s][s]=0;
	queue<int>q;
	q.push(s);
	while(q.size()){
		int u=q.front();
		q.pop();
		viss[u]=false;
		for(auto v:e[u]){
			if(dist[s][v.first]>dist[s][u]+1){
				dist[s][v.first]=dist[s][u]+1;
				if(!viss[v.first]){
					viss[v.first]=true;
					q.push(v.first);
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			a[i][j]=read(),t[i][j]=read();
			vis[{i,a[i][j]}]=true;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			for(int kk=1;kk<=k[i];kk++){
				if(vis[{j,a[i][kk]}])
				addedge(a[i][kk]+m*(i-1),a[i][kk]+m*(j-1),t[a[i][kk]][j]);
			}
		}
	}
	for(int i=1;i<=m*n;i++)spfa(i);
	while(q--){
		int x=read(),y=read();
		int ans=w[x]+w[y],mn=1e18;
		for(int i=x;i<=n*m;i+=m){
			for(int j=y;j<=n*m;j+=m){
				mn=min(mn,dist[i][j]);
			}
		}
		cout<<ans+mn<<'\n';
	}
	return 0;
}

