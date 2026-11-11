#include <bits/stdc++.h>
using namespace std;
long long x[2000005],n[2000005],d[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	for(int i=1;i<=t;i++){
		
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];j++){
			cin>>x[i];
		}
	}
	for(int i=1;i<=t;i++){
		cout<<n[i];
	}
	return(0);
}
