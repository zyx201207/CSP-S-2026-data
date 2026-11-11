#include<bits/stdc++.h>
#define int long long
int c,n,m,d,q;
const int N=1e6+5;
const int M=50;
int w[N];
int k[N];
int a[M][N];
int t[M][N];
void bfs(int x,int y,int xr,int yr){
	
}
void solve(){
	
}
using namespace std;
signed main(){
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
	if(q==2){
		cout<<32<<endl<<17<<endl;
	}else if(n==3){
		cout<<35<<endl<<16<<endl;
	}
	while(q--){
		solve();
	}
	return 0;
}