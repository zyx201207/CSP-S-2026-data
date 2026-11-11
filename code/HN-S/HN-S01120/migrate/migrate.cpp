#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,t,a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<n/2<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
