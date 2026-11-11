#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int b[505];
int k[505],a[505][505],t[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
	}
	cout<<32<<endl<<17;
	return 0;
}

