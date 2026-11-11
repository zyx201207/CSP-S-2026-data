#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x;
		for(int j=1;j<=x;j++) cin>>y;
	}
	while(q--){
		int x,y;
		cin>>x,y;
		cout<<x*n+y*m<<endl;
	}
	return 0;
}
