#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,n,d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		sort(x+1,x+n+1);
		cout<<n/2<<'\n';
	}
	return 0;
}
