#include <bits/stdc++.h>
using namespace std;
int n,d,a[2000005],c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(a[2]-a[1]>d||d/(a[2]-a[1])==1||d/(a[2]-a[1])>=n-1){
			cout<<0<<"\n";
			continue;
		}
		cout<<n-1-d/(a[2]-a[1])<<"\n";
	}
	return 0;
}
