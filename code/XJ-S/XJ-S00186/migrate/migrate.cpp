#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
const int N=2e6+5;
int a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int x=a[2]-a[1];
		if(2*x>d){
			cout<<"0\n";
			continue;
		}
		int cnt=d/x;
		int y=2*cnt;
		int z=max(0ll,n-y+1ll);
		cout<<z<<"\n";
	}
	return 0;
}
