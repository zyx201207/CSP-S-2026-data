#include <bits/stdc++.h>
using namespace std;
int n,tyh,c,T;
long long a[2000005],s[2000005],k[2000005],mi,ans,d,op;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;mi=2e18+1;
		for(int i=1;i<=n;i++)
			cin>>a[i],s[i]=a[i]-a[i-1]+s[i-1],k[i]=a[i]-a[i-1];
		k[1]=0;
		for(int i=2;i<=n;i++)
			mi=min(mi,a[i]-a[i-1]);
		if(d>=a[n]-a[1]){cout<<0<<"\n";continue;}
		if(mi>d){cout<<0<<"\n";continue;}
		for(int i=1;i<=n-3;i++)
			if(s[i+3]-s[i]>d&&s[i+3]-s[i]<=2*d&&a[i+3]-a[i+1]<=d&&a[i+3]-a[i+2<=d])
				op++;
		cout<<op<<"\n";op=0;
	}
	return 0;
}
/*

*/