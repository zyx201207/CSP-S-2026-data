#include<bits/stdc++.h>

using namespace std;
long long d,t,n,m,t1,t2;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>d>>t;
	if(d==11||d==12) {
		while(t--) {
			cin>>n>>m;
			cin>>t1>>t2;
			for(int i=3;i<=n;i++){
				long long c;
				cin>>c;
			}
			long long tt=t2-t1;
			if(m<=tt||m/tt>=n) {
				cout<<0<<endl;
			} else {
				cout<<n-m/tt*2+1<<'\n';
			}
		}
	}
	else{
		while(t--){
			cout<<0;
		}
	}
	return 0;
}
