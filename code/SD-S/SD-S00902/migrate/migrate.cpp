#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
int a[2002000];
int n,d;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		if (c==11 || c==12){
			int k=a[2]-a[1];
			if (d<2*k){
				cout<<0<<endl;
			}
			else {
				if (d>=(n-1)*k){
					cout<<0<<endl;
				}
				else{
					cout<<max(0ll,n-(2ll*(d/k)-1))<<endl;
				}
			}
		}
	}
	return 0;
}
