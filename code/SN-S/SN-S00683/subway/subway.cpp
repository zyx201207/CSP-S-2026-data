#include<bits/stdc++.h>
using namespace std;
int w[500005];
int k[505];
int a[505][500005];
int t[505][500005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int T=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			T=t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		
		
	}
	
	return 0;
} 
