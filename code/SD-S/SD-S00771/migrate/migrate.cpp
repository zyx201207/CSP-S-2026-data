#include<bits/stdc++.h>
using namespace std;
long long n,m,w[500005],k[505],a[505][100005],b[505][100005];
long long x,y,s,c,d,q;
vector<pair<long long,long long> > v[500005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&a,&b);
			v[a[i][j]].push_back({a[i][j-1],b[i][j]});
			v[a[i][j-1]].push_back({a[i][j],b[i][j]});
		}
	}
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		s=s+w[x]+w[y];
		cout<<n-i+1<<"\n";
	}
	return 0;
} 
