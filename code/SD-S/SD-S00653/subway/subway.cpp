#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,T;
int w[10000005];
int k,a[10000005],t[10000005];
int x[10000005],y[10000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i]>>t[i];
		}
	}
	T=t[1];
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		cout<<w[x[i]]+w[y[i]]+2*T+(n-1)*T<<endl;
	}
	return 0;
}
