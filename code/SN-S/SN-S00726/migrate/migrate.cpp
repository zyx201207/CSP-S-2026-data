#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,a[100010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		cout<<ceil(n*1.0/2)-1<<'\n';
	}
	return 0;
} 
