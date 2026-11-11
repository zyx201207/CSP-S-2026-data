#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int M[505],Time[505][505];
struct node{
	long long a;
	long long t;
}A[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>M[i];
	}
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=m;j++){
			Time[i][j]=999999;
			if(i==j) Time[i][j]=0;
		}
	}
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			cin>>A[i][j].a>>A[i][j].t;
			for(long long t=1;t<=j;t++){
				Time[A[i][t].a][A[i][j].a]=min(Time[A[i][t].a][A[i][j].a],A[i][t].t+A[i][j].t);
				Time[A[i][j].a][A[i][t].a]=min(Time[A[i][j].a][A[i][t].a],A[i][j].t+A[i][t].t);
			}
		}
	}
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=m;j++){
			for(long long k=1;k<=m;k++){
				Time[i][j]=min(Time[i][j],Time[i][k]+Time[k][j]);
			}
		}
	}
	for(long long i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		cout<<Time[x][y]+M[x]+M[y];
	}
	return 0;
}