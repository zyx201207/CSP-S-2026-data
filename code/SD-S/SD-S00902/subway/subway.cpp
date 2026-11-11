#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int w[500500];
int ans;
struct FJ{
	int to,len;
};
FJ a[5500][550];
int k[5500];
int vis[5500];
void dfs(int x,int y,int sum){
	if (sum>ans){
		return ;
	}
	if (x==y){
		ans=min(ans,sum);
	}
	for (int i=1;i<=k[x];i++){
		if (vis[a[x][i].to]==0){
			vis[a[x][i].to]=1;
			dfs(a[x][i].to,y,sum+a[x][i].len);
			vis[a[x][i].to]=0;
		}
	}
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k[m+i];
		for (int j=1;j<=k[m+i];j++){
			cin>>a[m+i][j].to>>a[m+i][j].len;
			k[a[m+i][j].to]++;
			a[a[m+i][j].to][k[a[m+i][j].to]].to=m+i;
			a[a[m+i][j].to][k[a[m+i][j].to]].len=a[m+i][j].len;
		}
	}
	for (int i=1;i<=q;i++){
		int s,t;
		cin>>s>>t;
		vis[s]=1;
		ans=1e9;
		dfs(s,t,0);
		vis[s]=0;
		cout<<ans+w[s]+w[t]<<endl;
	}
	return 0;
}
