#include<bits/extc++.h>
#define int long long
using namespace std;
using namespace __gnu_pbds;

int c,n,m,d,q,t[500001];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,b;
			cin>>a>>b;
		}
	}for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<t[x]+t[y]<<endl;
	}
}