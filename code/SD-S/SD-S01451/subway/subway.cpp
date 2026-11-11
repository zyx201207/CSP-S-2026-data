#include<bits/stdc++.h>
#define int long long
using namespace std;
int o,n,m,d,q,a[600000],c[1000][600000]={0};
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>o>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int u,tt;
			cin>>u>>tt;
			c[i][u]=tt;
		}
	}
	for(int kk=1;kk<=q;kk++){
		int x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
		for(int i=1;i<=n;i++){
			if(c[i][x]==0) 
		}
	}
	return 0;
}

