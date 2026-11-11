//SN-S00561 liuyuhe gxyzfdzx B
//last dance!
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M];
ll f[N][N];
struct edge{
	int to,cs;
};
vector<edge>ve[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k,a,t;i<=n;i++){
		cin>>k;
		while(k--) cin>>a>>t,ve[a].push_back({i,t});
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) if(i!=j) f[i][j]=1e18;
	for(int i=1;i<=m;i++)
		for(edge j:ve[i]) for(edge k:ve[i])
			f[j.to][k.to]=min(f[j.to][k.to],0ll+j.cs+k.cs);
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) if(f[i][k]<1e18)
		for(int j=1;j<=n;j++) if(f[k][j]<1e18) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;
		ll ans=1e18;
		cin>>x>>y;
		for(edge i:ve[x]) for(edge j:ve[y])
			ans=min(ans,f[i.to][j.to]+w[x]+w[y]+i.cs+j.cs);
		cout<<ans<<"\n";
	}
	return 0;
}
