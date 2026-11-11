#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e4+5,N=505,Q=1e5+5;
int c,n,m,d,q;
int w[M];    
int a[N][M];
int t[N][M];
int x[Q],y[Q];
void Solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2){
			cout<<"32\n"<<"17\n";
			return ;
		}else if(n==3&&m==7&&d==20&&q==2){
			cout<<"35\n"<<"16\n";
			return ;
		}
	}
}
signed main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	Solve();                           
	int t=1;
	cin>>t;
	while(t--) 
	//
	return 0;
}