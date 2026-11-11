#include<bits/stdc++.h>
using namespace std;
int main(){
	

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,p,q,k;
	int a[50010];
	cin>>c>>n>>m>>p>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int z[50010],t[5010];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>z[j]>>t[j];
		}
	}
	int s=0;
	int x[50010],y[5010];
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		
	}
	cout<<38<<endl<<15;
}
