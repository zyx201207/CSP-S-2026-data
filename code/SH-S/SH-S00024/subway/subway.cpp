#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=514514;
int c,n,m,d,q;
int w[N],a[514][N],t[514][N],k[514];
vector<int>g[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			g[a[i][j]].push_back(i);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		
	}
	return 0;
}
