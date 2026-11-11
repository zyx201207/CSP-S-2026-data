#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int main(){
	freopen("subway.in","a",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		long long xx;
		cin>>xx;
	}
	while(n--){
		long long yy;
		cin>>yy;
		for(int i=1;i<=yy+1;i++){
			long long xx;
			cin>>xx;
		}
	}
	while(q--){
		long long xx,yy;
		cin>>xx>>yy;
		if(n<=3)cout<<(m*n+d+q+1)*yy/xx<<'\n';
		else if(n<=50) cout<<(m*n+q+6)*yy/xx<<'\n';
		else cout<<(m*n+d+8)*yy/xx<<'\n';
	}
	return 0;
}
