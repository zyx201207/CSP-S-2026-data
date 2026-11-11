#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=502,M=5e5+5;
int C,n,m,D,q;
ll d[N][N],w[M];
vector<int>t[M];
vector<int>num[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL); 
	cin>>C>>n>>m>>D>>q; 
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		int k,x;cin>>k;
		for(int j=1;j<=k;++j){
			int T;
			cin>>x>>T;
			num[x].push_back(i),t[x].push_back(T); 
		}
	}
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=n;++i)d[i][i]=0;
	for(int i=1;i<=m;++i){
		int l=num[i].size();
		for(int j=0;j<l;++j)for(int k=j+1;k<l;++k){
			int a=num[i][j],b=num[i][k];
			ll tmp=1ll*t[i][j]+1ll*t[i][k];
			if(tmp<d[a][b])d[a][b]=d[b][a]=tmp;
		}
	} 
	for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
		if(d[i][k]+d[k][j]<d[i][j])d[i][j]=d[i][k]+d[k][j];
	for(int i=1;i<=q;++i){
		int x,y;ll ans=1e18;cin>>x>>y;
		if(x==y){cout<<"0\n";continue;}
		for(int i=0;i<num[x].size();++i)for(int j=0;j<num[y].size();++j){
			int t1=num[x][i],t2=num[y][j];
			ll tmp=w[x]+w[y]+1ll*t[x][i]+1ll*t[y][j]+d[t1][t2];
			if(tmp<ans)ans=tmp; 
		}
		cout<<ans<<"\n";
	}
	return 0;
}
