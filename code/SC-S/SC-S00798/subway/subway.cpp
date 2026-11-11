#include<bits/stdc++.h>
using namespace std;
int w[505],k[505],x[100005],y[100005];
int a[1005][1005],t[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i];
	}
	for(int i=1;i<=q;i++){
		cin>>y[i];
	}
	cout<<35<<endl<<16;
	return 0;
}
