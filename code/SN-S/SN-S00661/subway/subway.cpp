#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;
ll c,n,m,d,q;
ll k,a,t,x,y;
ll w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
		}
	}
	while(q--){
		cin>>x>>y;
	}
	return 0;
}
