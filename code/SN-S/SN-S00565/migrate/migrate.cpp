#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+10;
ll a[N],c,t,n,d,b[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		
		ll cha=a[2]-a[1];
		if(cha>=d||n==1){
			cout<<0<<"\n";
		}else{
			cout<<max((ll)0,n-(2*(d/cha)-1))<<"\n";
		}
	}
	return 0;
}
