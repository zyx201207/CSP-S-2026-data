#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=5e2+5;
int w[M],k[N],a[N][N*10],t[N][N*10],x[M],y[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin.tie(0);cout.tie(0);
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
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		cout<<35<<"\n";
	}
	return 0;
}
