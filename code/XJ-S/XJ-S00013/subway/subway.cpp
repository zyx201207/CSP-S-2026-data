#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int w[N],k[505],a[505][25005],t[505][25005];
int ans=0x3f,x1,y;
vector<int> g[N];
int tong[N];
void dfs(int x,int time){
	if(x==y){
		ans=min(ans,time);
		return;
	}
	int p;
	for(int i=1;i<=tong[x];i++){
		for(int j=1;j<=k[g[x][i]];j++){
			if(a[g[x][i]][j]==x) p=j;
		}
		for(int j=1;j<=k[g[x][i]];j++)
		{
			if(a[g[x][i]][j]!=x){
				dfs(a[g[x][i]][j],time+t[g[x][i]][p]+t[g[x][i]][j]);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){//
		cin>>w[i];//
	}//
	for(int i=1;i<=n;i++){//
		cin>>k[i];//
		for(int j=1;j<=k[i];j++){//
			cin>>a[i][j]>>t[i][j];//
			g[a[i][j]].push_back(i);
			tong[a[i][j]]++;
		}
	}
	while(q--){
		ans=0x3f;
		cin>>x1>>y;
		dfs(x1,0);
		cout<<w[x1]+w[y]+ans<<'\n';
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
