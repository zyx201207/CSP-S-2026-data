#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
ll a[maxn],dis[1000][1000],c,n,m,d,q;
vector<pair<ll,ll> > hc[maxn];
vector<int> bel[maxn];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	for(int i = 0; i < 1000; i++) dis[i][i]=0;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i <= m; i++) cin>>a[i];
	for(int i = 1; i <= n; i++){
		ll k;
		cin>>k;
		for(int j = 1; j <= k; j++){
			ll id,ti;
			cin>>id>>ti;
			bel[id].push_back(i);
			//cout<<i<<' '<<id<<' '<<ti<<'\n';
			if(hc[id].size()>0){
				for(int l = 0; l < hc[id].size(); l++){
					if(dis[i][hc[id][l].first]>hc[id][l].second+ti){
						dis[i][hc[id][l].first]=hc[id][l].second+ti;
						dis[hc[id][l].first][i]=hc[id][l].second+ti;
					}
				}
			}
			hc[id].push_back({i,ti});
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			if(dis[i][k]==0x3f3f3f3f3f3f3f3f) continue;
			for(int j = 1; j <= n; j++){
				if(dis[k][j]==0x3f3f3f3f3f3f3f3f) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
	for(int i = 1; i <= q; i++){
		ll s,t;
		cin>>s>>t;
		ll mn=0x3f3f3f3f3f3f3f3f;
//		if(i==1){
//			cout<<bel[s].size()<<' '<<bel[t].size()<<'\n';
//		}
		for(int j = 0; j < bel[s].size(); j++){
			for(int k = 0; k < bel[t].size(); k++){
				ll tmp=dis[bel[s][j]][bel[t][k]];
				tmp+=a[s];
				tmp+=a[t];
				ll aa,bb;
				for(int l = 0; l <hc[s].size(); l++){
					if(hc[s][l].first==bel[s][j]){
						aa=l;
						break;
					}
				}
				for(int l = 0; l <hc[t].size(); l++){
					if(hc[t][l].first==bel[t][k]){
						bb=l;
						break;
					}
				}
				tmp+=hc[s][aa].second;
				tmp+=hc[t][bb].second;
				//cout<<dis[bel[s][j]][bel[t][k]]<<' '<<a[s]<<' '<<a[t]<<' '<<hc[s][aa].second<<' '<<hc[t][bb].second<<' '<<bel[s][j]<<' '<<bel[t][k]<<' '<<aa<<' '<<bb<<'\n';
				mn=min(tmp,mn);
			}
		}
		cout<<mn<<'\n';
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++) cout<<dis[i][j]<<' ';
//		cout<<'\n';
//	}
	return 0;
}