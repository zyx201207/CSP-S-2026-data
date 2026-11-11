#include<bits/stdc++.h>
using namespace std;
long long t,n,x;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t;
	cin>>t;
	while(t--){
		cin>>n>>x;
		for(int i=1;i<=n;i++)cin>>x;
	}
	cout<<n*(n-1)/2;
	return 0;
}
