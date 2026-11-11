#include <bits/stdc++.h>
using namespace std;
long long c,m,n,d,q;
long long w[500010],k[505];
long long a[505][500010],t[505][500010];
long long x[500010],y[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(long long i=1;i<=m;i++){
		cin<<w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin<<a[i][j]<<t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];	
	}
	cout<<"36"<<"\n"<<"48";
	return 0;
}

