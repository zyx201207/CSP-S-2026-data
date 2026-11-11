#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
//	if(c==11||c==12){
		while(t--){
			long long n,d;
			cin>>n>>d;
			for(long long i=1;i<=n;i++){
				cin>>a[i];
			}
			d/=a[2]-a[1];
			cout<<max(n-2*d+1,0ll)<<'\n';
		}
//	}
	return 0;
}
