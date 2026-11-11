#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5,inf=1e18;
int w[N],k[N],t[4][N],p[N],a;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)  cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a;cin>>a;  p[a]+=i;
			cin>>t[i][a];
		}
	}
	int res=inf;
	for(int i=1;i<=m;i++){
		if(p[i]==3)  res=min(res,t[1][i]+t[2][i]);
	}
	for(int i=1;i<=q;i++){
		int l,r;  cin>>l>>r;
		if(p[l]==3||p[r]==3)  
			cout<<w[l]+w[r]+min(t[1][l]+t[1][r],t[2][l]+t[2][r]);
		else if(p[l]==p[r]){
			cout<<w[l]+w[r]+t[p[l]][l]+t[p[l]][r];
		}
		else {
			cout<<w[l]+w[r]+res+t[p[l]][l]+t[p[r]][r];
		}
	}
	return 0;
}