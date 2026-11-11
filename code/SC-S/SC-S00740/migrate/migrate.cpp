#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const ll mx=2e6+10;
ll c,t,n,d,a[mx];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}	
			ll s=d/(a[2]-a[1]);
			if(s<=1){
				cout<<0<<endl;
				continue;
			}
			ll m=2*s-1;
			if(n-m<=0) cout<<0<<endl;
			else cout<<n-m<<endl;
		}
	}
	return 0;
}