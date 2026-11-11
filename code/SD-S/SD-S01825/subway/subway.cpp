#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int s,f;
//m范围？ 
int w[5005];
int a[505][5005];
int t[505][5005];
int vis[5005];
long long minn=0x3f3f3f3f;
void dfs(int x,long long sumt){
	if(x==f){
		minn=min(minn,sumt);
		return ;
	}
	if(sumt>=minn){
		return ;
	}
	vis[x]=1;
	for(int i=1;i<=n;i++){
		if(a[i][x]==1){//有线路 
			if(a[i][f]==1&&vis[f]==0){//线路可以直通终点 
				vis[f]=1;
				dfs(f,sumt+t[i][x]+t[i][f]+w[f]);
				vis[f]=0;
			}else{
				for(int j=i+1;j<=m;j++){//枚举换乘点 
					if(a[i][j]==1&&vis[j]==0){
						vis[j]=1;
						dfs(j,sumt+t[i][x]+t[i][j]);
						vis[j]=0;
					}
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int j;
			cin>>j;
			a[i][j]=1;//表示i条线路经过地铁站j
			cin>>t[i][j];//表示从j站厅到 i站台 
		}
	}
	while(q--){
		minn=0x3f3f3f3f;
		cin>>s>>f;	 
		dfs(s,w[s]);//从起点地铁口到站厅
		cout<<minn<<'\n';
	}
	return 0;
}
