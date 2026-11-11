#include<bits/stdc++.h>
using namespace std;
long long c,t,n,s[2000005],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		cin>>s[j];
		if(d<2*(s[2]-s[1]))
		cout<<0<<endl;
		else
		cout<<max(n-2*d/(s[2]-s[1])+1,n-n)<<endl;
	}
	return 0;
} 
