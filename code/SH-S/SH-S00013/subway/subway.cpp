#include<bits/stdc++.h>
using namespace std;
long long w[500010],a[500010][500010],t[500010][500010],k[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		cin>>k[i];
	}
	for(int i=1;i<=m;i++){
		for(int i=1;i<=k;i++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
	cout<<endl;
	}
	return 0;
}
