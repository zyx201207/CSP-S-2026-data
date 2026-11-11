#include<bits/stdc++.h>
using namespace std;
long long w[500005],h[505][505];
vector<pair<int,int>>g[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(h,0x3f3f3f,sizeof(h));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int ai,ti;
			cin>>ai>>ti;
			g[ai].push_back({i,ti}); 
		}
	}for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			long long id1=g[i][j].first,t1=g[i][j].second;
			for(int k=0;k<g[i].size();k++){
				int id2=g[i][k].first,t2=g[i][k].second;
				if(id1==id2)continue;
				h[id1][id2]=h[id2][id1]=min(h[id1][id2],t1+t2);
			}
		}
	}for(int i=1;i<=n;i++)h[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(h[i][k]<1e18&&h[j][k]<1e18)
					h[i][j]=min(h[i][j],h[i][k]+h[j][k]);
			}
		}
	}while(q--){
		int l,r;
		cin>>l>>r;
		long long mi=1e18;
		for(int i=0;i<g[l].size();i++){
			for(int j=0;j<g[r].size();j++){
				int li=g[l][i].first,ri=g[r][j].first;
				long long lw=g[l][i].second,rw=g[r][j].second;
				mi=min(mi,h[li][ri]+w[l]+w[r]+lw+rw);
			}
		}cout<<mi<<'\n';
	}
}