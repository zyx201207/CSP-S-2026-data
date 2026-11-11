#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5,Q=1e5+5;
int c,n,m,d,q,ans=0x3f3f3f3f,vis[N];
int w[M];
int k[N],a[N][M],t[N][M];
int x[Q],y[Q],now,p;
vector<int> v[N];
void dfs(int r,int sum){
    if(r==y[now])
        ans=min(ans,sum+t[p][r]);
	for(int i=0;i<v[r].size();i++){
		int x=v[r][i];
		if(!vis[x])
			dfs(x,sum+t[p][x]);
	}
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	for(int r=1;r<=q;r++)
		cin>>x[r]>>y[r];
	for(int x=1;x<=n;x++){
		for(int i=1;i<k[x];i++)
			for(int j=i+1;j<=k[x];j++)
				v[i].push_back(j);
	}
	for(int i=1;i<=n;i++){
	    ans=0x3f3f3f3f;
        now=i;p=1;
        dfs(x[now],w[x[now]]+w[y[now]]);
        cout<<ans<<endl;
	}
	return 0;
}
