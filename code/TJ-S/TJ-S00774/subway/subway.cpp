#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int M=5e5+5;
int w[M],a[505][505],t[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a_,t_;
			cin>>a_>>t_;
			a[i][a_]=1,t[i][a_]=t_;
		}
	}
	while(q--){
		int x,y,sum=0x3f3f3f3f;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			if (a[i][x]&&a[i][y]) sum=min(sum,w[x]+t[i][x]+t[i][y]+w[y]);
		}
		cout<<sum<<"\n";
	}
	return 0;
}

