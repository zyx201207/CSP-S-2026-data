#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=509,M=5e5+9,Inf=1e18+9;
int c,n,m,d,q,w[M],kk,a,t,f[N][N],minn;
vector<pair<int,int> > too[N],tto[M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=Inf;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>kk;
		for(int j=1;j<=kk;j++){
			cin>>a>>t;
			too[i].push_back({a,t});
			tto[a].push_back({i,t});
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<too[i].size();j++){
			a=too[i][j].first;
			t=too[i][j].second;
			for(int k=0;k<tto[a].size();k++){
				if(tto[a][k].first==i)continue;
				f[i][tto[a][k].first]=min(f[i][tto[a][k].first],t+tto[a][k].second);
				f[tto[a][k].first][i]=f[i][tto[a][k].first];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
			}
		}
	}
	while(q--){
		cin>>a>>t;minn=Inf;
		for(int i=0;i<tto[a].size();i++){
			for(int j=0;j<tto[t].size();j++){
				minn=min(minn,tto[a][i].second+tto[t][j].second+
					f[tto[a][i].first][tto[t][j].first]);
			}
		}
		cout<<w[a]+w[t]+minn<<"\n";
	}
	return 0;
}
