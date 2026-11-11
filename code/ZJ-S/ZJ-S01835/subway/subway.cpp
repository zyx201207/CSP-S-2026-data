#include<bits/stdc++.h>
using namespace std;
const int MAXM=5e5+10;
const int MAXN=5e2+10;
long long c,n,m,d,q,w[MAXM],k[MAXN],x,y;
vector <long long> a[MAXN];
vector <long long> t[MAXN];
struct Line{
	long long sta,line;
};
vector <Line> to[MAXM];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(long long j=1,lx;j<=k[i];j++){
			scanf("%lld%lld",&x,&y);
			a[i].push_back(x);
			t[i].push_back(y);
			if(j-1){
				to[lx].push_back({x,i});
				to[x].push_back({lx,i});
			}
			lx=x;
		}
	}
	while(q--){
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",w[x]+w[y]);
	}
	return 0;
}