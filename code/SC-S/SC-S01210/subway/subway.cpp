#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct box{
	int v=0,s=0;
}a[N];
struct aox{
	int v,e;
};
struct cmp{
	operator()(aox x,aox y){
		return x.e>y.e;
	} 
};
priority_queue<int,vector<aox>,cmp> q;
vector<aox> b[N];
int dis[N],vis[N];
int c,n,m,d,qq;
int more[N];
void dij(int start){
	int i,j;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[start]=0;
	q.push({start,0});
	while(!q.empty()){
		aox t=q.top();
		q.pop();
		if(vis[t.v]==1)continue;
		vis[t.v]=1;
		int len=b[t.v].size();
		for(i=0;i<len;i++){
			aox z=b[t.v][i];
			if(vis[t.v]==0){
				q.push({z.v,z.e});
				dis[z.v]=dis[t.v]+z.e;
				vis[t.v]=1;
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int i,j;
	cin>>c>>n>>m>>d>>qq;
	for(i=1;i<=m;i++){
		cin>>more[i];
	}
	memset(b,0,sizeof(b));
	int z=0,zz=0;
	for(i=1;i<=n;i++){
		int x;
		cin>>x;
		z=0;
		zz=0;
		for(j=1;j<=x;j++){
			cin>>a[j].v>>a[j].s;
			if(j>1){
				b[z].push_back({a[j].v,a[j].s+zz});
				b[a[j].v].push_back({z,a[j].s+zz});
			}
			z=a[j].v;
			zz=a[j].s;
		}
	}
	int start,end;
	for(i=1;i<=qq;i++){
		cin>>start>>end;
		dij(start);
		cout<<more[start]+dis[end]+more[end];
	}
	return 0;
}