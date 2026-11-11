#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=5e5+10;
const long long INF=0x3f3f3f3f3f3f3f3f;
vector<pair<int,long long>>g[M];
long long w[M];
int c,n,m,d,q;
long long fl[N][N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(fl,0x3f,sizeof fl);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		fl[i][i]=0;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u;long long wi;
			cin>>u>>wi;
			g[u].push_back({i,wi});
		}
	}
	for(int i=1;i<=m;i++){
		for(int l=0;l<(int)g[i].size();l++){
			for(int r=l+1;r<(int)g[i].size();r++){
				int vl=g[i][l].first,vr=g[i][r].first;
				long long wl=g[i][l].second,wr=g[i][r].second;
				fl[vl][vr]=min(fl[vl][vr],wl+wr);
				fl[vr][vl]=min(fl[vr][vl],wl+wr);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				fl[i][j]=min(fl[i][j],fl[i][k]+fl[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		long long ans=INF;
		for(int si=0;si<(int)g[s].size();si++){
			for(int ei=0;ei<(int)g[e].size();ei++){
				ans=min(ans,g[s][si].second+g[e][ei].second+fl[g[s][si].first][g[e][ei].first]);
			}
		}
		ans=ans+w[s]+w[e];
		cout<<ans<<"\n";
	}
	return 0;
}