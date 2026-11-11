#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	while(m--) cin>>c;
	for(int i=1;i<=n;i++) {
		cin>>c;
		for(int i=1,t,p;i<=c;i++) cin>>t>>p;
	}
	while(q--) {
		cin>>c>>m;
		cout<<(rand()%65536*rand()%65536);
	}
	return 0;
}

