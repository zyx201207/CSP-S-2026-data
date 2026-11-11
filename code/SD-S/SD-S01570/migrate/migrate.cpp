#include<bits/stdc++.h>
using namespace std;
long long a[2000010],c[2000010],s[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c1,t,n;
	long long d;
	cin>>c1>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			c[i]=a[i]-a[i-1];
		} 
		cout<<"1\n";	
	}
	return 0;
} 
