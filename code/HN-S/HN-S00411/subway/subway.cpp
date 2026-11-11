#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5;
ll c,n,m,d,q;
ll a[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ll l;
		cin>>l;
		for(int j=1;j<=l;j++){
			int x,y;
			cin>>x>>y;
		} 
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<x+y<<"\n"; 
	}
	return 0;
}
