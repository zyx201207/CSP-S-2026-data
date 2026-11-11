#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int W[500005];
vector<pair<int,int>>g[500505];
int chn[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>W[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		int lu=i+m;
		for(int j=1;j<=k;j++){
			int ting,w;cin>>ting>>w;
			g[lu].push_back({ting,w});
			g[ting].push_back({lu,w});
		}
	}
	memset(chn,0x3f,sizeof chn);
	for(int i=1;i<=n;i++)chn[i][i]=0;
	for(int i=1;i<=m;i++)
		if((int)g[i].size()>1)
			for(int j=0;j<(int)g[i].size();j++)
				for(int k=j+1;k<(int)g[i].size();k++){
					int v1=g[i][j].first-m,w1=g[i][j].second;
					int v2=g[i][k].first-m,w2=g[i][k].second;
					chn[v1][v2]=min(chn[v1][v2],w1+w2);
				}
	for(int len=2;len<=n;len++)
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			for(int k=1;k<=n;k++)
				if(k!=l&&k!=r)
					chn[l][r]=min(chn[l][r],chn[l][k]+chn[k][r]);
		}
	
	while(q--){
		int x,y;cin>>x>>y;
		if(x>y)swap(x,y);
		int ans=LONG_LONG_MAX;
		for(auto [v1,w1]:g[x])
			for(auto [v2,w2]:g[y])
				ans=min(ans,w1+w2+chn[v1-m][v2-m]);
		cout<<ans+W[x]+W[y]<<"\n";
	}
	
	return 0;
}