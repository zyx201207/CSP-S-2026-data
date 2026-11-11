#include<bits/stdc++.h>
using namespace std;
struct qp{
	long long xl,t;
};
vector<qp>v[500050];
long long c,n,m,d,q,w[500050],a[510][510];
inline long long rd(){
	long long x=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd();n=rd();m=rd();d=rd();q=rd();
	for(long long i=1;i<=m;i++){
		w[i]=rd();
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			a[i][j]=1e18;
		}
	}
	for(long long i=1;i<=n;i++){
			a[i][i]=0;
	}
	for(long long i=1;i<=n;i++){
		long long o;
		o=rd();
		for(long long j=1;j<=o;j++){
			long long x,y;
			x=rd();y=rd();
			for(long long k=0;k<v[x].size();k++){
				a[v[x][k].xl][i]=min(a[v[x][k].xl][i],v[x][k].t+y);
				a[i][v[x][k].xl]=min(a[v[x][k].xl][i],v[x][k].t+y);
			}
			v[x].push_back({i,y});
		}
	}
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	for(long long i=1;i<=q;i++){
		long long x,y;
		x=rd();
		y=rd();
		long long ans=1e18;
		for(long long j=0;j<v[x].size();j++){
			for(long long k=0;k<v[y].size();k++){
				ans=min(ans,v[x][j].t+v[y][k].t+a[v[x][j].xl][v[y][k].xl]);
			}
		}
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}