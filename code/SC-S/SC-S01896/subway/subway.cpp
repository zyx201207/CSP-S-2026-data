#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=502;
const int M=5e5+5;

ll k[N];
ll w[M];
ll a[N][M];
ll t[N][M];
ll dep[M];
ll c,n,m,d,q;

ll query(int x,int y){
	if(x==y){return 0;}
	
	return (-1);
}

int main(){
	cin>>c>>n>>m>>d>>q;	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<query(x,y)<<'\n';
	}
	return 0;
}