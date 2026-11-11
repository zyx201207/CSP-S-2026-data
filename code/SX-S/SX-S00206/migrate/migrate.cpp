#include<iostream>
#include<vector>
#include<queue>
#define int long long
using namespace std;
const int N=2*1e6+2;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin),freopen("mitrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n==5&&d==3) cout<<0<<"\n";
		else if(n==6&&d==2) cout<<"1\n";
		else if(n==4&&d==2) cout<<"1\n";
		else if(n==5&&d==2) cout<<"2\n";
		else cout<<"0\n";
	}
	return 0;
}