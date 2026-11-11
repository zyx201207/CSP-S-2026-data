#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const int M=5e5+10;
const ll INF=1e18;
ll w[M],a[N][M],t[N][M];

int dfs(int x,int y,int step){
	if(x==y){
		
	}
}
int main(){
	freopen("hub.in","r",stdin);//!!!
	freopen("hub.out","w",stdout);//!!!
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		
	}
	return 0;
}
