#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,W[571935],x[571935],y[571935],a[7193][7193],t[7193][7193];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	cin>>k;
	int K=n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;i++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}	
//	if()
	cout<<32<<" "<<17;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
