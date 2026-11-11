#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int w[500010];
int k[510];
int a[510][510],t[510][510];
int x[100010],y[100010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=p;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=p;i++){
		cout<<(w[x[i]]+w[y[i]])+2<<endl;
	}
	return 0;
}

