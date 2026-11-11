#include<bits/stdc++.h>
using namespace std;
long long c , t , n , d , a[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++)cin>>a[i];
		if(a[n]-a[1]<=d)cout<<0<<endl;
		else cout<<1<<endl;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

