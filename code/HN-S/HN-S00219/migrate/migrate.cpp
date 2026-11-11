#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof a);
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		
		if(a[2]-a[1]>=d){
			cout<<0<<"\n";
		}
		else{
			cout<<n-3<<"\n";
		}
	}
	return 0;
}
