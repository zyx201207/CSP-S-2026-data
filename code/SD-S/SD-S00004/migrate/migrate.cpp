#include<bits/stdc++.h>
using namespace std;
const int N=2000007;
int c,t;
long long n,d;
long long a[N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>t;
	for (int i=1; i<=t; i++) {
		cin>>n>>d;
		for (int i=1; i<=n; i++) {
			cin>>a[i];
		}
		int f=0;
		int qw=a[2]-a[1];
		for (int i=2; i<=n; i++) {
			if (a[i]-a[i-1]!=qw) {
				f=1;
			}
		}
		if (f==0) {
			if (qw>d){
				cout<<"0"<<endl;
			}
			else{
				if (d-qw>=2){
					cout<<"0"<<endl;
				}
				else{
					cout<<(n-1)/d<<endl;
				}
			}
		} else {
			cout<<"0"<<endl;
		}
	}
	return 0;
}
