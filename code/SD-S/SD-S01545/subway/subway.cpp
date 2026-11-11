#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+5,N=505;
int c,n,m,d,q,w[M],k[N],x,y,a[N][M],t[N][M],sum;
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
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		sum=w[x]+t[x][x]+t[x][y]+w[y];
	}
	cout<<sum<<endl;
	return 0;
} 
