#include <bits/stdc++.h>
using namespace std;
const int M=500002,N=502;
int C,n,m,d,q,w[M],len[N],c[M];
vector<int> a[N],t[N];
unordered_map<int,int> id[N];
long long f[N][N];
vector<int> be[M];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>len[i];
		a[i].resize(len[i]+2),t[i].resize(len[i]+2);
		for(int j=1;j<=len[i];j++) cin>>a[i][j]>>t[i][j],be[a[i][j]].push_back(i);
		for(int j=1;j<=len[i];j++) 
			id[i][a[i][j]]=j;
	} 
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++) f[i][j]=1e18;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=len[i];j++) c[a[i][j]]=j;
		for(int j=i+1;j<=n;j++)
			for(int k=1;k<=len[j];k++)
				if(c[a[j][k]]>0) f[i][j]=f[j][i]=min(f[i][j],(long long)(t[i][c[a[j][k]]] + t[j][k]));
		for(int j=1;j<=len[i];j++) c[a[i][j]]=0;
	}
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int l,r;
		long long ans=0,res=1e18;
		cin>>l>>r;
		for(int xx:be[l])
			for(int yy:be[r])
				res=min(res,t[xx][id[xx][l]]+t[yy][id[yy][r]]+f[xx][yy]);
		cout<<res+w[l]+w[r]<<'\n';
	}
	return 0;
}
