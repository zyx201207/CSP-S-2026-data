#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p;
int w[500010],a[510][500010],x[100010],y[100010],b[510][500010];
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++){
			cin>>a[i][j]>>b[i][j];
		}
	}
	for(int i=1;i<=p;i++){
		cin>>x[i]>>y[i];
	}
	
	return 0;
}
//
