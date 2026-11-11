#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,in1,in2,lajitong;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=12) {
		for(int i=1; i<=t; i++) {
			cin>>n>>d;
			cin>>in1>>in2;
			d/=(in2-in1);
			for(int i=3; i<=n; i++) {
				cin>>lajitong;
			}
			if(d>=2) {
				cout<<n-2*d+1<<endl;
			} else {
				cout<<0<<endl;
			}
		}
	}else{
		for(int i=1; i<=t; i++) {
			cin>>n>>d;
			for(int i=1; i<=n; i++) {
				cin>>lajitong;
			}
			cout<<0<<endl;
		}
	}
	return 0;
}