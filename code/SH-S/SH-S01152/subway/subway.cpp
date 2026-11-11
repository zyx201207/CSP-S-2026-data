#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=500009;
const ll N=509;
struct xlzt{
	ll id,t;
};
vector <xlzt> zt[M];
ll c,n,m,d,q,w[M],t[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			zt[a].push_back((xlzt){i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) t[i][j]=0;
			else t[i][j]=1e16;
		}
	}
	for(int u=1;u<=m;u++){
		if(zt[u].size()<=1) continue;
		for(int i=0;i<zt[u].size()-1;i++){
			for(int j=i+1;j<zt[u].size();j++){
				t[zt[u][i].id][zt[u][j].id]=min(t[zt[u][i].id][zt[u][j].id],zt[u][i].t+zt[u][j].t);
				t[zt[u][j].id][zt[u][i].id]=min(t[zt[u][j].id][zt[u][i].id],t[zt[u][i].id][zt[u][j].id]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int X,Y;
		cin>>X>>Y;
		int XSZ=zt[X].size();
		int YSZ=zt[Y].size();
		ll ans=1e17;
		for(int XXX=0;XXX<XSZ;XXX++){
			for(int YYY=0;YYY<YSZ;YYY++){
				ans=min(ans,t[zt[X][XXX].id][zt[Y][YYY].id]+zt[X][XXX].t+zt[Y][YYY].t);
			}
		}
		ans+=w[X];
		ans+=w[Y];
		cout<<ans<<'\n';
	}
	return 0;
}
