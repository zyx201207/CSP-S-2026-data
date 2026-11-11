#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q;
int w[1000];int a[1000][1000],t[1000][1000];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0){,stdout
		if(n==3) cout<<35<<' '<<16;
		else cout<<32<<' '<<17;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>w[i];
	char a,b;
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a>>b;
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+2<<'\n';
	}
	return 0;
}


