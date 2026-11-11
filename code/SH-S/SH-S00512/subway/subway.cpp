#include<bits/stdc++.h>
using namespace std;
long long minn;
bool check[510];
long long c,n,m,d,q,x,y;
long long edge[510][510];
bool have[510][510];
long long w[510000],k[510];
long long t[510][510];
vector<pair<long long,long long> > a[510];
vector<pair<long long,long long> > lines[510000];
vector<pair<long long,long long> > connected[510];
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > dp;
void dij(long long start){
	memset(check,false,sizeof(check));
	t[start][start]=0;
	dp.push(make_pair(0,start));
	while(!dp.empty()){
		auto now=dp.top();
		dp.pop();
		check[now.second]=true;
		for (auto i:connected[now.second]){
			if (check[i.first]){
				continue;
			}
			if (t[start][i.first]>now.first+i.second){
				t[start][i.first]=now.first+i.second;
				dp.push(make_pair(t[start][i.first],i.first));
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	memset(t,127,sizeof(t));
	memset(edge,127,sizeof(edge));
	for (long long i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for (long long i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for (long long j=1;j<=k[i];j++){
			scanf("%lld %lld",&x,&y);
			a[i].push_back(make_pair(x,y));
			lines[x].push_back(make_pair(i,y));
		}
	}
	for (long long i=1;i<=m;i++){
		for (auto p1:lines[i]){
			for (auto p2:lines[i]){
				if (p1.first==p2.first){
					continue;
				}
				edge[p1.first][p2.first]=min(edge[p1.first][p2.first],p1.second+p2.second);
				have[p1.first][p2.first]=true;
			}
		}
	}
	for (long long i=1;i<=n;i++){
		for (long long j=1;j<=n;j++){
			if (have[i][j]){
//				cout<<i<<' '<<j<<' '<<edge[i][j]<<endl;
				connected[i].push_back(make_pair(j,edge[i][j]));
			}
		}
	}
	for (long long i=1;i<=n;i++){
		dij(i);
	}
	for (long long i=1;i<=q;i++){
		minn=1e18;
		scanf("%lld %lld",&x,&y);
		for (auto xlines:lines[x]){
			for (auto ylines:lines[y]){
//				cout<<xlines.first<<' '<<xlines.second<<' '<<ylines.first<<' '<<ylines.second<<endl;
				minn=min(minn,xlines.second+t[xlines.first][ylines.first]+ylines.second);
			}
		}
		printf("%lld\n",minn+w[x]+w[y]);
	}
	return 0;
}
