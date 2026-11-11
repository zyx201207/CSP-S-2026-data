#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll c,n,m,d,q,k1,l,r;
ll w[500010];
struct che{
	ll z,t;
}a[500010][30];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k1;
		for(int j=1;j<=k1;j++){
			cin>>a[i][j].z>>a[i][j].t;
		}
	}
	
	while(q--){
		cin>>l>>r;
		
	}
	return 0;
}
