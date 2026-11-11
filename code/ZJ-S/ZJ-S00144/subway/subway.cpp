#include<bits/stdc++.h>
using namespace std;
long long w[505],a[405][405],t[405][405],f[405][405];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 	long long c,n,m,d,q;
 	cin>>c>>n>>m>>d>>q;
 	for(long long i=1;i<=m;i++) cin>>w[i];
 	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		} 
	} 
	for(long long i=0;i<405;i++) for(long long j=0;j<405;j++) f[i][j]=INT_MAX;
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]+w[k]+t[i][k]+t[k][j]);
			}
		}
	}
	while(q--){
		long long l,r;
		cin>>l>>r;
		cout<<f[l][r]+w[l]+w[r]<<'\n'; 
	}
	return 0;
} 
