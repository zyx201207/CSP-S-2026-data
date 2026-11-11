#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
ll n,d,x[2000005];
ll p[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	ll k=x[2]-x[1];
	ll m=d/k;
	ll cnt=0;
	for(int i=1;i<=n;i++){
		p[i]=(i-1)/m;
		if(p[i]*m!=(i-1)){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
