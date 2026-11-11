#include<bits/stdc++.h>
using namespace std;
long long x[100005];
int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	long long c,t,n,d;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<(n-d-1)<<"\n";
	}
	return 0;
}
