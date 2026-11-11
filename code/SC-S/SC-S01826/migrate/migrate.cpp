#include<bits/stdc++.h>
using namespace std;
int t;
int c;
long long n,d;
long long x[2101010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<n*(n-1)/2<<"\n";
	}
	return 0;
}