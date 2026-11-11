#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("sudway.out","w",stdout);
	long long dist[505][505]={};
	long long c,n,m,d,q,w[500005],k[505],ma[505][505],cnt[500005]={};
	memset(ma,0x3f3f3f3f,sizeof ma);
	struct A{
		vector<pair<long long,long long> > t;
	}a[500005];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		ma[i][i]=0;
	} 
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int e,f;
			cin>>e>>f;
			a[e].t.push_back({i,f});
			for(int o=0;o<cnt[e];o++){
				ma[a[e].t[o].first][i]=min(ma[a[e].t[o].first][i],a[e].t[o].second+a[e].t[i].second);
				ma[i][a[e].t[o].first]=ma[a[e].t[o].first][i];
			}
			cnt[e]++;
		}
	}
	for(int j=1;j<=n;j++){
		bool visted[505]={};
		visted[j]=1;
		memset(dist,0x3f3f3f3f,sizeof dist);
		int cn=1;
		for(int i=1;i<=n;i++)dist[j][i]=ma[j][i];
		while(cn<n){
			int re=0x3f3f3f3f,dot=0;
			for(int i=1;i<=n;i++){
				if(!visted[i]){
					if(dist[j][i]<re){
						re=dist[j][i];
						dot=i;
					}
				}
			}
			visted[dot]=1;
			cn++;
			for(int i=1;i<=n;i++)dist[j][i]=min(dist[j][i],ma[dot][i]);
		}
	}
	for(int i=1;i<=q;i++){
		long long x,y,ans=0x3f3f3f3f;
		cin>>x>>y;
		for(int e=0;e<cnt[x];e++){
			for(int f=0;f<cnt[y];f++){
				ans=min(ans,dist[a[x].t[e].first][a[y].t[f].first]+a[x].t[e].second+a[y].t[f].second);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
} 