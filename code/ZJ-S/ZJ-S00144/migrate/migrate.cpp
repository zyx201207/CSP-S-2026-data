#include<bits/stdc++.h>
using namespace std;
long long n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	long long c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cout<<n*(n+1)/2;
	}
	return 0;
} 
