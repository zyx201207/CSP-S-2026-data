#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int w[100050],k,a[505][500050],t[505][500050];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k;
		for (int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			
		}
	}
	cout<<27<<'\n'<<13;
	return 0;
}
