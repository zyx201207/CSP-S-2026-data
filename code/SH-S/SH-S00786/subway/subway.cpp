#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=500+10,Maxm=5e5+10;
int c,n,m,d,q,w[Maxm],num[Maxn],f[Maxn][Maxn],i,j,k,u,v,xx,yy,ww,zz;
vector<pair<int,int> >s[Maxm]; 
vector<int>a[Maxn];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++) cin>>w[i];
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	if(i!=j) f[i][j]=1e18;
	for(i=1;i<=n;i++){
		cin>>num[i];
		for(j=1;j<=num[i];j++){
			cin>>xx>>yy;
			a[i].push_back(yy);
			s[xx].push_back({i,j-1});
		}
	}
	for(i=1;i<=m;i++){
		for(j=0;j<s[i].size();j++)
		for(k=0;k<s[i].size();k++){
			u=s[i][j].first,v=s[i][k].first;
			xx=s[i][j].second,yy=s[i][k].second;
			f[u][v]=min(f[u][v],a[u][xx]+a[v][yy]);
		}
	}
	for(k=1;k<=n;k++)
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	f[j][i]=f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		cin>>u>>v;
		int ans=1e18;
		for(j=0;j<s[u].size();j++)
		for(k=0;k<s[v].size();k++){
			xx=s[u][j].first,yy=s[v][k].first,ww=s[u][j].second,zz=s[v][k].second;
			ans=min(ans,f[xx][yy]+a[xx][ww]+a[yy][zz]+w[u]+w[v]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
