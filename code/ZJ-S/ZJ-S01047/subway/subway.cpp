#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
const int M=5e2+10;
ll c,n,m,d,q,x,y;
ll w[N],k[N],a[M][N],t[M][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		cin>>x>>y;
	}
	
	return 0;
}
