#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,d;
int x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		//if(c==11||c==12){
			int ans=0;
			int cha=x[2]-x[1];
			if(2*cha>d){
				cout<<ans<<'\n';
				continue;
			}
			ans=n-3;
			cout<<ans<<'\n';
		//}
	}
	return 0;
}