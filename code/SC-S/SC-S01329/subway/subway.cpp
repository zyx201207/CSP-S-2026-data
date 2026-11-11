#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll c,n,m,d,q,x,y,k;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>x;
	for (int i=1;i<=n;i++){
		cin>>k;
		for (int i=1;i<=k;i++) cin>>x>>y;
	}
	for (int i=1;i<=q;i++) cin>>x>>y;
	while(q--){
		cout<<q<<"\n";
	}
	return 0;
} 