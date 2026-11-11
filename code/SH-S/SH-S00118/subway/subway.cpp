#include<bits/stdc++.h>
using namespace std;
int zz,n,m,q;
int w[500001];
int k[501];
map<pair<int,int>,int> a;
map<pair<int,int>,int> t;
int lc[500001];
long long s[501][501];
long long c[500001][21];
long long d[501][501];
vector<int>g[501];
queue<int>v;
void bfs(){
	for(int aa = 1;aa <= n;aa++)
		for(int bb = 1;bb <= n;bb++)
			for(int cc = 1;cc <= n;cc++){
				if(s[bb][aa]!=2e9&&s[aa][cc]!=2e9)
				d[bb][cc]=min(d[bb][cc],1LL*s[bb][aa]+1LL*s[aa][cc]);
			}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&zz,&n,&m,&zz,&q);
	for(int i = 1;i <= m;i++)
		scanf("%d",&w[i]);
	for(int i = 1;i <= n;i++){
		scanf("%d",&k[i]);
		for(int j = 1;j <= k[i];j++){
			scanf("%d",&a[{i,j}]);
			scanf("%d",&t[{i,a[{i,j}]}]);
		}
	}
	memset(lc,0,sizeof(lc));
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= k[i];j++){
			lc[a[{i,j}]]++;
			c[a[{i,j}]][lc[a[{i,j}]]]=i;
		}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++){
			s[i][j]=2e9;
			s[i][i]=0;
			d[i][j]=1e18;
		}
	for(int i = 1;i <= m;i++)
		for(int j= 1;j <= lc[i];j++)
			for(int l = j+1;l <= lc[i];l++){
				s[c[i][j]][c[i][l]]=min(s[c[i][j]][c[i][l]],t[{c[i][j],i}]+t[{c[i][l],i}]);
				s[c[i][l]][c[i][j]]=min(s[c[i][l]][c[i][j]],t[{c[i][j],i}]+t[{c[i][l],i}]);
			}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++){
			if(s[i][j]==2e9)
				continue;
			g[i].push_back(j);
		}
	for(int i = 1;i <= n;i++){
		d[i][i]=0;
	}
	bfs();
	for(int i = 1;i <= q;i++){
		int o,p;
		scanf("%d%d",&o,&p);
		long long ans = 1e18;
		for(int j = 1;j <= lc[o];j++)
			for(int l = 1;l <= lc[p];l++){
				if(d[c[o][j]][c[p][l]]!=1e18){
					ans=min(ans,d[c[o][j]][c[p][l]]+t[{c[o][j],o}]+t[{c[p][l],p}]);
				}
			}
		ans+=1LL*w[o];
		ans+=1LL*w[p];
		printf("%lld\n",ans);
	}
    return 0;
}
