#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000001;
struct st{
	int i,t;
};
vector<st>v[N];
int n,m,Q,c,d,X,Y,k,a,t,f[521][521],w[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++){
		int D=v[i].size();
		for(int j=0;j<D;j++){
			for(int k=j+1;k<D;k++){
				st x=v[i][j],y=v[i][k];
				f[x.i][y.i]=f[y.i][x.i]=min(f[x.i][y.i],x.t+y.t);
			}
		}
	}
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
			}
		}
	}
	while(Q--){
		cin>>X>>Y;
		int ans=0x3f3f3f3f3f3f3f3f;
		int d1=v[X].size(),d2=v[Y].size();
		for(int i=0;i<d1;i++){
			for(int j=0;j<d2;j++){
				st x=v[X][i],y=v[Y][j];
				ans=min(ans,x.t+f[x.i][y.i]+y.t);
			}
		}
		cout<<ans+w[X]+w[Y]<<"\n";
	}
	return 0;
}
//Oct31==Dec25? 
