#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[100010],k[5010],a[600][10000],t[600][10000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin >>w[i];
	}
	for(int i=1;i<=n;i++){
		cin >>k[i];
		for(int j=1;j<=k[i];j++){
			cin >>a[i][j];
		}
		for(int j=1;j<=k[i];j++){
			cin >>t[i][j];
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin >>x>>y;
			cout <<x*y;
		}
	}
	return 0;
}
