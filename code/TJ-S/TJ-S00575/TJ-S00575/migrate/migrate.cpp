#include<bits/stdc++.h>
using namespace std;
int c,t;
int x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=0;k<t;k++){
		int n,z;
		cin>>n>>z;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<n-2*z+1;
	}
	return 0;
}
