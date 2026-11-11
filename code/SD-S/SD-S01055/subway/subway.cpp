#include<bits/stdc++.h>
#define int long long
#define PLL pair<int,int>
#define endl '\n'
using namespace std;
const int N=5e5+5;
int kkll,n,m,d,q,p[N],c[505][505];
vector<PLL> to[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(c,0x3f,sizeof c);
	scanf("%lld%lld%lld%lld%lld",&kkll,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&p[i]);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			scanf("%lld%lld",&x,&y);
			to[x].push_back(make_pair(i,y));
		}
	}
	for(int i=1;i<=m;i++){
		int len=to[i].size(); 
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				c[to[i][j].first][to[i][k].first]=min(c[to[i][j].first][to[i][k].first],to[i][j].second+to[i][k].second);
				c[to[i][k].first][to[i][j].first]=min(c[to[i][k].first][to[i][j].first],c[to[i][j].first][to[i][k].first]);
			}
		}
	}
	for(int i=1;i<=n;i++) c[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
			}
		}
	}
	while(q--){
		int x,y,ans=1e18;
		scanf("%lld%lld",&x,&y);
		for(PLL i:to[x]){
			for(PLL j:to[y]){
				if(i.first==j.first){
					ans=min(ans,i.second+j.second);
				}
				else{
					ans=min(ans,i.second+j.second+c[i.first][j.first]);
				}
			}
		}
		printf("%lld\n",ans+p[x]+p[y]);
	}
	return 0;
}
