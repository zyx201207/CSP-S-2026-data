#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[10007],dis[7007][7007],sum;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		long long l=x[2]-x[1],base=1;
		while(base*l<=d){
			base++;
		}
		base--;
		for(int i=1;i<base;i++){
			sum+=(n-base-i);
		}
		cout<<sum<<endl;
	}
	return 0;
}

