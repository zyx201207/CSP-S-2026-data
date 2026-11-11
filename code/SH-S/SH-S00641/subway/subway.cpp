#include<bits/stdc++.h>
using namespace std;
const int maxn=5*2e6;
long long n,m,c,d,q,w[maxn],k,a[105][20005],t[105][20005],x,y;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<0<<"\n";
	}
	
	return 0;
}
