#include<bits/stdc++.h>
using namespace std;

int w[500010];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>c;
		for(int j=1;j<=c*2;j++) cin>>d;
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<w[a]+w[b]+d*4<<"\n";
	}
	return 0;
}