#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,a[500005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrite.out","w",stdout);
	cin>>c>>t;
	for(int c=1;c<=t;c++){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<n-2*m+1<<"\n";
	}
	
	
}
