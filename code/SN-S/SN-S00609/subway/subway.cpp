#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxm = 5e5+10;
ll c,n,m,d,q,w[maxm],k[505],a[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		cin>>k[i];
		for(int v=1;v<=k[i]*2;v++){
			cin>>a[i][v];
		}
		for(int j=1;j<=q;j++){
			ll x,y;
			cin>>x>>y;
			
		}
	}
	
}
