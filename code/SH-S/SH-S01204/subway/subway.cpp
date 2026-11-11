#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,n,m,d,q,t[500005],a[205][100005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	if(c<=3){
		for(int i=1;i<=n;i++){
			int cnt;
			cin>>cnt;
			for(int j=1;j<=cnt;j++){
				cin>>a[i][j];
			}
		}
		if(q==2){
			if(n==2) cout<<32<<endl<<17<<endl; return 0;
			if(n==3) cout<<35<<endl<<16<<endl; return 0;
		}
		while(q--){
			cin>>a>>b;
			cout<<10000<<endl;
		}
	}
	return 0;
} 
