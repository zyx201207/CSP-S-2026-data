#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,i,x,s,a,b;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (i=1;i<=n;i++) cin>>x,s+=x;
	for (i=1;i<=n;i++){
		cin>>x;
		for (i=1;i<=x;i++) cin>>a>>b,s+=b;
	}
	while(q--) cout<<s<<"\n";
}
