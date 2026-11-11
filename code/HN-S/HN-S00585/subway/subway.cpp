#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int N=500005,M=505,r=100005;
int c,n,m,d,q,w[N],a[M][N],t[M][N],x[r],y[r],tim[r],k[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		};
	};
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	};
	if((n==1)&&(d>=n)){
		for(int i=1;i<=q;i++){
			tim[i]=0;
			for(int j=x[i];j<=y[i];j++){
				int of=w[j]+t[1][j];
				tim[i]=tim[i]+of;
			};
			cout<<tim[i]<<endl;
		};
	};
	return 0;
}
