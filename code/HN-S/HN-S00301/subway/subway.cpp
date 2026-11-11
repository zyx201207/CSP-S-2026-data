#include<bits/stdc++.h>
using namespace std;
const int maxn = 100001;
int w[maxn],a[maxn][maxn],t[maxn][maxn],x[maxn],y[maxn];
int main(){
	int c,n,m,d,q,k;
	cin>>c>>n>>m>>d>>q;
	int g = 0;
	for(int i = 1;i <= m;i++){
		cin>>w[i];
	}
	for(int i = 1;i <= n;i++){
		cin>>k;
		for(int j = 1;j <= k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i = 1;i <= q;i++){
		cin>>x[i]>>y[i];
	}
	int o,u;
	for(int j = 1;j <= q;j++){
		o = x[j];
		u = y[j];
		g = w[o]+w[u];
		for(int i = 1;i <= n-1;i++){
			for(int p = 1;p <= k;p++){
				g = t[i][p]+g;
			}
		}
		cout<<g;
	}
	return 0;
}
