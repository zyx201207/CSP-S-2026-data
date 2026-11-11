#include <bits/stdc++.h>
using namespace std;
int w[100100],a[10100][10100],k[100100],t[100100],li[10000][10000];
queue<int>que;
int main(){
	int c,n,m,d,q;
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int j=1;j<=n;j++){
		cin>>k[j];
		for(int i=1;i<=k[j];i++){
			cin >> a[j][i]>>t[i];
		} 
	}
	
	while(q--){
		int st,en;cin >> st>>en;
		
		
	}

	return 0;
}
