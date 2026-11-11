#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(a[4]-a[1]>d){
			cout<<n-3<<"\n";
		}else{
			cout<<0<<"\n";
		}
		
	}
	
	return 0;
}
