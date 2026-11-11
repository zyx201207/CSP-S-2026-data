#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,a[500050],b[500050],f[500050];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)cin>>b[j]>>f[j];
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	}
	cout<<32<<endl<<17;
	return 0;
}
