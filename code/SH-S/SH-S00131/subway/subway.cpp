#include<bits/stdc++.h>
using namespace std;
const int N=509;
const int M=5e5+9;
const int INF=1e9;
int c,n,m,d,q;
int w[N];
vector<int> edge[N+M];
vector<int> len[N+M];
int dst[N+M];
int cnt[N+M];
void dfs(int x,int fa){
	//cout<<x<<endl;
	cnt[x]++;
	if(cnt[x]>edge[x].size()){
		return;
	}
	int sz=edge[x].size();
	for(int i=0;i<sz;i++){
		int y=edge[x][i];
		if(y==fa){
			continue;
		}
		if(dst[x]+len[x][i]<dst[y]){
			dst[y]=dst[x]+len[x][i];
		}
		dfs(y,x);
	}
	return;
}
int main(){ 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			edge[a].push_back(m+i);
			len[a].push_back(t);
			edge[m+i].push_back(a);
			len[m+i].push_back(t);
		}
	}
	/*for(int i=1;i<=n+m;i++){
		for(int j=0;j<edge[i].size();j++){
			cout<<edge[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		fill(dst,dst+n+m+1,INF);
		fill(cnt,cnt+n+m+1,0);
		dst[x]=0;
		dfs(x,0);
		/*for(int i=1;i<=n+m;i++){
			cout<<dst[i]<<" ";
		}
		cout<<endl;*/
		cout<<(dst[y]+w[x]+w[y])<<endl;
	}
	return 0;
}
