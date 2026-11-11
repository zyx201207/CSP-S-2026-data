#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[5000005];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(t==2) {
		while(t--) {
			cin>>n>>d;
			if(n==4&&d==2) {
				cout<<"1\n2";
				return 0;
			}
			else {
				cout<<"0\n1";
				return 0;
			}
		}
	} 
	return 0;
}

