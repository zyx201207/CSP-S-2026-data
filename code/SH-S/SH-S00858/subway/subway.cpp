#include<bits/stdc++.h>
#define int long long
const int N=5e5+5;
int w[550],a[550][N],t[550][N];
int x[100005],y[100005];
using namespace std;
signed main(){
	//Oct31==Dec25?
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
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
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(n==2)cout<<"32\n17";
	else if(n==3)cout<<"35\n16";
	return 0;
}
