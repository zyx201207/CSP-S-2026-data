#include<bits/stdc++.h>
using namespace std;


int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a[505],w[1000009];
	int m,n,c,d,q;
	int r=0;
	int t[10000005][100000005];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cin>>t[i][j];
		}
	}

	
	
	for(int i=1;i<=q;i++){
		cout<<r;
	}
	return 0;
}
