#include<bits/stdc++.h>
using namespace std;
long long d[500010];
long long a[510000];
long long c[510000];
long long dp[510000];
bool  cc[510000];
pair<long long ,long long>s[1020000];
int ide=0;
void add(long long u,long long v,long long w){
	s[++ide]={a[u],v};
	a[u]=ide;
	c[ide]=w;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long ccc,m,n,dd,qq;
	cin >>ccc>>m>>n>>dd>>qq;
	for(int i=1;i<=n;i++){
		cin >>d[i];
	}
	int p=n;
	for(int i=1;i<=m;i++){
		int g=0;
		cin >>g;
		p++;
		int y1,y2;
		for(int j=1;j<=g;j++){
			cin >>y1>>y2;
			add(p,y1,y2);
			add(y1,p,y2);
		}
	}
	int ss,zz;
	while(qq--){
		cin >>ss>>zz;
		for(int i=1;i<=n+m+1;i++){
			dp[i]=10000000000000000;
			cc[i]=0;
		}
		priority_queue<pair<long long,long long> >q;
		q.push({0,ss});
		dp[ss]=0;
		while(!q.empty()){
			long long o=q.top().second;
			q.pop();
			if(cc[o]==1)continue;
			cc[o]=1;
			for(int i=a[o];i!=0;i=s[i].first){
				if(dp[s[i].second]>dp[o]+c[i]){
					dp[s[i].second]=dp[o]+c[i];
					q.push({-dp[s[i].second],s[i].second});
				}
			}
		}
		cout <<dp[zz]+d[ss]+d[zz]<<"\n"; 
	}
	return 0;
} 