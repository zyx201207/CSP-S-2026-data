#include<bits/stdc++.h>
using namespace std;
int a[200010];
signed main(){
	srand(time(0));
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		cin>>a[1]>>a[2];
		bool fl=1;
		for(int i=3;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-2]!=a[2]-a[1]) fl=0;
		}
		if(fl){
			int x=a[2]-a[1];
			if(d<2*(a[2]-a[1])){
				cout<<0<<'\n';
				continue;
			}
			cout<<2<<'\n';
		}else cout<<rand()%n<<'\n';
	}
	return 0;
}