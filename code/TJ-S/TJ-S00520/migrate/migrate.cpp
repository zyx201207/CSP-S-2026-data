#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2*1e6+5;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, t;
	cin>>c>>t;
	while(t--){
		int n, d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int cha=a[2]-a[1];
		if(d<cha){
			cout<<0<<endl;
			continue;
		}else if(d==cha){
			cout<<n-3<<endl;
		}else{
			cout<<d/cha*n<<endl;
		}
	}
	return 0;
}

