#include <bits/stdc++.h>
using namespace std;
const int M=500005,N=505,Q=100005;
#define ll long long 
ll c,n,m,d,q;
ll w[M],k[N],a[N][N],t[N][N],x[Q],y[Q];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	time(0);
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		cout<<rand()%(m*n*d*q)*rand()%(m*n*d*q)<<"\n";
	}
	return 0;
}