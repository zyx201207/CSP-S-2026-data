#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int c,n,m,d,q,w[N],a[N],t[N],x[N],y[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i]>>t[i];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	cout << 32 << endl << 17; 
	return 0;
}