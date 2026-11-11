#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500010];
vector<vector<pair<long long,long long>>> st;
long long g[510][510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,0x3f,sizeof(g));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	st.resize(m+1);
	for(int i=1;i<=m;++i){
		scanf("%lld",&w[i]);
	}
	for(int i=0;i<n;++i){
		long long k;
		scanf("%lld",&k);
		for(int j=0;j<k;++j){
			long long a,t;
			scanf("%lld%lld",&a,&t);
			st[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=0;j<st[i].size();++j){
			for(int k=j+1;k<st[i].size();++k){
				g[0][st[i][j].first][st[i][k].first]=g[0][st[i][k].first][st[i][j].first]=st[i][j].second+st[i][k].second;
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				g[k][i][j]=min(g[k-1][i][j],g[k-1][i][k-1]+g[k-1][k-1][j]);
				if(i==j)g[k][i][j]=0;
			}
		}
	}
	for(int i=0;i<q;++i){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		long long ans=0x7fffffffffffffff;
		for(pair<int,int> j:st[x]){
			for(pair<int,int> k:st[y]){
				ans=min(ans,g[n][j.first][k.first]+j.second+k.second);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}