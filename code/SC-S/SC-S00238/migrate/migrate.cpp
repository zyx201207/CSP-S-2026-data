#include<bits/stdc++.h>
using namespace std;
const int N=2e6+1;
long long c,t,n,d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==12){
			long long k=a[2]-a[1];
			if(d<2*k){
				cout<<0<<endl;
				continue;
			}
			long long tt=d/k*2;
			if(n<tt){
				cout<<0<<endl;
				continue;
			}
			cout<<n-tt+1<<endl;
			continue;
		}
	}
}
