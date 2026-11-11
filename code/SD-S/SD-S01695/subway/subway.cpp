#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,ti=0;
long long w[500005];
long long a[1006][1006];
long long t[1006][1006];
long long u[1006][1006];
//void dfs(long long o){
//	if(o==y){
//		return;
//	}
//	for(int i=1;i<=u[o].size();i++){
//		dfs(u[o][i]);
//	}
//	
//	
//}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
//			u[a[i][j]][a[i][j-1]]=1;
//			u[a[i][j-1]][a[i][j]]=1;
		}
	}
	while(q--){
		cin>>x>>y;
		ti=w[x]+t[x][1]+w[y]+t[y][2];
		//dfs(x);
		cout<<ti<<endl;
	}
	return 0;
}
