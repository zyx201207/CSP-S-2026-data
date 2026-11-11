#include<bits/stdc++.h>
using namespace std;
int T=1;
long long w[500005],ans;
int c, n, m, d, q,a[505][500005],b[500005][505],aaa[505][500005];
long long hc[505][505]={1e10};
int f[505],ttt;
void dfs(int x,long long y){
	f[ttt]=x;
	ttt++;
	for(int i=1;i<=aaa[x][0];i++){
		int ops=aaa[x][i];
		for(int j=1;j<=b[ops][0];j++){
			bool pd=0;
			for(int k=1;k<=ttt;k++)if(f[k]==b[ops][j])pd=1;
			if(pd)continue;
			long long yy=y+a[b[ops][j]][ops]+a[x][ops];
			hc[min(x,b[ops][j])][max(x,b[ops][j])]=min(hc[min(x,b[ops][j])][max(x,b[ops][j])],yy);
			dfs(b[ops][j],yy);
		}
	}
	ttt--;
	f[ttt]=0;
}

int main(){
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	while(T--){
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++){
			cin>>aaa[i][0];
			for(int j=1;j<=aaa[i][0];j++)
			{
				cin>>aaa[i][j];
				cin>>a[i][aaa[i][j]];
				b[aaa[i][j]][0]++;
				b[aaa[i][j]][b[aaa[i][j]][0]]=i;
			}
			dfs(1,0);
			
			for(int i=1;i<=q;i++){
				int ax,ay;
				cin>>ax>>ay;
				cout<<w[ax]+w[ay]+hc[min(ax,ay)][max(ax,ay)]<<endl;
			}
		}
	}
	return 0;
}
