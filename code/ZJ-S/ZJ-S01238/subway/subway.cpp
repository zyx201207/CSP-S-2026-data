#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;
int w[N],k[505];
int a[505][N],t[505][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x;
			cin>>x;
			a[i][x]=1;
			cin>>t[i][x];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n*n;j++){
			cout<<a[i][j]<<" ";
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i) continue;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		
	}
	*/
	
	
	return 0;
}
