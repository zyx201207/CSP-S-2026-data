#include<bits/stdc++.h>
#define lglg long long
using namespace std;

int cid,n,m,d,q;lglg w[500005];
lglg f[505][505];
vector<pair<int,lglg> >V[500005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>cid>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=(i==j?0ll:200000000000000005ll);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int len;cin>>len;
		while(len--){
			int x;lglg v;cin>>x>>v;
			V[x].push_back(make_pair(i,v));
		}
	}
	for(int i=1;i<=m;i++){
		int siz=V[i].size();
		for(int o=0;o<siz;o++)for(int oo=0;oo<o;oo++){
			f[V[i][o].first][V[i][oo].first]=min(f[V[i][o].first][V[i][oo].first],V[i][o].second+V[i][oo].second);
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[j][i]);
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		lglg v=f[i][k]+f[k][j];if(v<f[i][j])f[i][j]=v;
	}
	while(q--){
		int x,y;lglg ca=200000000000000005ll;cin>>x>>y;
		if(x==y){cout<<"0\n";continue;}
		for(auto uu:V[x])for(auto we:V[y])ca=min(ca,f[uu.first][we.first]+uu.second+we.second);
		cout<<ca+w[x]+w[y]<<'\n';
	}
	return 0;
}
