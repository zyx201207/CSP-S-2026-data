#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500005
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+1];
	for(int i=1;i<=m;i++) cin>>w[i];
	int a[N][N],t[N][N];
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				if(x==a[i][j]) sum+=t[i][j];
				if(y==a[i][j]) sum+=t[i][j];
			}
		}
		sum+=w[x]+w[y];
		cout<<sum<<'\n';
	}
	return 0;
}
