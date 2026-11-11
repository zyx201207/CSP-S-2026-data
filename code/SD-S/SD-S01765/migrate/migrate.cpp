#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+5;
ll n,m,op,T,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>op>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1; i<=n; i++){
			cin>>a[i];
		}
		ll ans,sum=1e18;
		for(int i=1; i<=n; i++){
			ans=a[i]-a[1];
			if(ans>m){
				sum=2*i-2;
				break;
			}
		}
		cout<<max(n-sum+1,0ll)<<endl;
	}
	return 0;
} 
//Oct31==Dec25?
