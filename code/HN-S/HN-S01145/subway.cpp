#include<bits/stdc++.h>
using namespace std;
long long n,m,k,l,r,z,mi,a[500010],b[510][510];
vector<long long> v[500010],v2[500010];
int main(  ){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	cin>>n>>m>>k;
	cin>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[i][j]=1e17;
		}
		b[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>z;
		for(int j=1;j<=z;j++){
			cin>>l>>r;
			v[l].push_back(i);
			v2[l].push_back(r);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size( );j++){
			for(int i2=0;i2<v[i].size( );i2++){
				b[v[i][j]][v[i][i2]]=min(b[v[i][j]][v[i][i2]],v2[i][j]+v2[i][i2]);
				b[v[i][i2]][v[i][j]]=min(b[v[i][i2]][v[i][j]],v2[i][j]+v2[i][i2]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int i2=1;i2<=n;i2++){
				b[j][i2]=min(b[j][i2],b[j][i]+b[i][i2]);
			}
		}
	}
	for(int i=1;i<=k;i++){
		cin>>l>>r;
		mi=1e17;
		for(int j=0;j<v[l].size( );j++){
			for(int i2=0;i2<v[r].size( );i2++){
				mi=min(mi,b[v[l][j]][v[r][i2]]+v2[l][j]+v2[r][i2]);
			}
		}
		cout<<mi+a[l]+a[r]<<"\n";
	}
	return 0;
}
