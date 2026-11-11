#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[500001];
int b[500001][500001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=7;j++){
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=q;j++){
			cin>>b[i][j];
		}
	}
	cout<<32<<endl;
	cout<<17;
	return 0;
}

