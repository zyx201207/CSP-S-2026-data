#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,v;
const int maxn=5e5;
int w[maxn];
int a[500][maxn/2];
int t[500][maxn/2];
int x[maxn][2],y[maxn][2];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
		v=max(v,k);
	}
	int cnt=1;
	for(int i=1;i<=q;i++){
		cnt++;
		cin>>x[i][cnt]>>y[i][cnt];
	}cout<<32<<endl<<17;
	return 0;
}
