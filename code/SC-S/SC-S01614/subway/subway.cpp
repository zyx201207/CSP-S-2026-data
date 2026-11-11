#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=505;
int c,n,m,d,p,ans=0;
int w[N],a[N][N],t[N][N];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>p;
	w[0]=0;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		w[i]=w[i-1]+w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		} 
	}
	for(int i=1,x,y;i<=p;i++){
		cin>>x>>y;
		cout<<w[y]-w[x-1]+t[x][y]<<endl;
	}
	return 0;
}
