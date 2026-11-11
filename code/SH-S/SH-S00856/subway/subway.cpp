#include<bits/stdc++.h>
using namespace std;
void init(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
const int N=309;
int c,n,m,d,q,k,rx,ry;
int w[N],a[N][N],t[N][N];
void bfs(int st,int ed){
	long long ans=w[st]+w[ed];
}
int main(){
	//init();
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>rx>>ry;
		bfs(rx,ry);
	}
	return 0;
}

