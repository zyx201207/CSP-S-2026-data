#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+10;
const int K=5e5+10;
int w[N],a[N][K],t[N][K],
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
