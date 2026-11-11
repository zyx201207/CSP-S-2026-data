#include<bits/stdc++.h>
using namespace std;
int n,c,t,z;
long long d;
long long a[2000005];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	for(int k=1; k<=t; k++) {
		long long cot=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int i=1; i<n-2; i++) {
			for(int j=i+3; j<=n; j++) {
				if(a[j]-a[i]>=2*d)
					j+=n;
				else if((a[i+2]-a[i]<=d&&a[i+3]-a[i]>d&&a[j]-a[i+1]<=d)||(a[j]-a[j-2]<=d&&a[j]-a[j-3]>d&&a[j-1]-a[i]<=d)) {
					cot++;
				}
			}
		}
		cout<<cot<<endl;
	}
	return 0;
}
