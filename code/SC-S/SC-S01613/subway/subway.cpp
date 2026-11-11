#include<bits/stdc++.h>
using namespace std;
int n,c,m,d,q;
struct ls{
	int to,next;
	long long w;
}edge[3000];
int cnt=1,head[500000];
void add(int u,int v,long long w){
	edge[cnt].w=w;
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
long long w[6000000];
int k[600];
long long sum=1e9;
bool vv[500000];
void dfs(int x,int y,int ans){
	//cout<<"x="<<x<<endl;
	vv[x]=1;
	if(x==y){
		if(ans<sum)sum=ans;
		return;
	}
	for(int i=head[x];i!=0;i=edge[i].next){
		int v=edge[i].to;
		long long ww=edge[i].w;
		if(!vv[v]&&ans+ww<sum)dfs(v,y,ans+ww);
		vv[v]=0;
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int v;
			long long ww;
			cin>>v>>ww;
			add(i+m,v,ww);
			add(v,i+m,ww);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		memset(vv,0,sizeof(vv));
		sum=1e9;
		dfs(x,y,0);
		//way[x][y]=sum;
		cout<<sum+w[x]+w[y]<<"\n";
	}
	
	return 0;
} 