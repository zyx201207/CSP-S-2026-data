#include<bits/stdc++.h>
#define int long long
#define mid ((nl+nr)>>1)
#define f1 first
#define s2 second
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[500005],dis[505][505];
vector<pair<int,int> >vc[500005];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) dis[i][j]=inf;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			if(vc[a].size()){
				for(auto x:vc[a]){
					dis[i][x.f1]=min(dis[i][x.f1],t+x.s2);
					dis[x.f1][i]=min(dis[x.f1][i],t+x.s2);
				}
			}
			vc[a].emplace_back(i,t);
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y,ans=inf;
		cin>>x>>y;
		for(auto s:vc[x]){
			for(auto t:vc[y]){
				ans=min(ans,dis[s.f1][t.f1]+s.s2+t.s2);
//				cout<<ans<<" "<<s.f1<<" "<<s.s2<<" "<<t.f1<<" "<<t.s2<<"\n";
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
