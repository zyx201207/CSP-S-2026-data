#include<bits/stdc++.h>
using namespace std;
vector<int>a[500005];
vector<long long>b[500005];
int head[510],data[2000010],Next[2000010];
long long w[2000010];
long long u[2000010];
int tot=0;
void add(int x,int y,long long z){
	data[++tot]=y;
	w[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}
long long ans[505][505];
void bfs(int k){
	queue<int>q;
	q.push(k);
	ans[k][k]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x];i!=-1;i=Next[i]){
			if(ans[k][data[i]]>ans[k][x]+w[i]){
				ans[k][data[i]]=ans[k][x]+w[i];
				q.push(data[i]);
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(head,-1,sizeof head);
	memset(ans,0x3f,sizeof ans);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>u[i];
	}
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		for(int j=1;j<=t;j++){
			int x;
			long long y;
			cin>>x>>y;
			a[x].push_back(i);
			b[x].push_back(y);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<=a[i].size()-1;j++){
			for(int k=j+1;k<=a[i].size()-1;k++){
				add(a[i][j],a[i][k],b[i][j]+b[i][k]);
				add(a[i][k],a[i][j],b[i][j]+b[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long mnn=1e18;
		for(int i=0;i<=a[x].size()-1;i++){
			for(int j=0;j<=a[y].size()-1;j++){
				mnn=min(mnn,ans[a[x][i]][a[y][j]]+b[x][i]+b[y][j]);
			}
		}
		cout<<mnn+u[x]+u[y]<<'\n';
	}
	return 0;
}
