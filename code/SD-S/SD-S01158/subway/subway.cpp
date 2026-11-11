#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=505;
#define int long long
int c,n,m,d,q,p[M],f[N][N];
struct l{
	int s,t;
};
vector<l>st[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>p[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int sto,tm;cin>>sto>>tm;
			st[sto].push_back({i,tm});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			f[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int u=0;u<st[i].size();u++){
			for(int v=0;v<u;v++){
				int w=st[i][u].t+st[i][v].t,l=st[i][u].s,r=st[i][v].s;
				f[l][r]=min(f[l][r],w);
				f[r][l]=min(f[r][l],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int l,r,ans=1e18;
		cin>>l>>r;
		for(int u=0;u<st[l].size();u++)
			for(int v=0;v<st[r].size();v++){
				ans=min(ans,f[st[l][u].s][st[r][v].s]+st[l][u].t+st[r][v].t);
			}
				
		cout<<ans+p[l]+p[r]<<'\n';
	}
	return 0;
}

