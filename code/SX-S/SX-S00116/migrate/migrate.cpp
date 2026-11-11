#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505000;
ll c,T,n,d,a[N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		ll ch=abs(a[n]-a[n-1]);
		if(3*ch<=d||ch>d){
			cout<<"0\n";
			continue;
		}
		if(2*ch<=d){
			cout<<n-3<<"\n";
			continue;
		}
		else if(ch<=d){
			cout<<n-2<<"\n";
			continue;
		}
	}
	return 0;
}
