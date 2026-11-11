#include<bits/stdc++.h>
long long a[2000005];
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n==1)cout<<0;
		else if(n==2){
			if(a[1]+d<a[2])cout<<0;
			else cout<<1;
		}
		else cout<<(n-1)/2;
		cout<<"\n";
	}
	return 0;
}
