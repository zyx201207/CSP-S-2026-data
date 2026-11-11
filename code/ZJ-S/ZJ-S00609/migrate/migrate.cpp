#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int s=a[2]-a[1];
		int sum=d-s;
		if(n%sum){
			cout<<"0\n";
		}
		else{
			cout<<n-d-s<<'\n';
		}
	}
	return 0;
}
