#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
int c,n,m,d,q;
int w[M],a[505][M],t[505][M];
int f[505];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=0;i<n;i++){
		int k;
		for(int j=1;j<=k;j++)cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(find(x)==find(y)){
		}
	}
}
