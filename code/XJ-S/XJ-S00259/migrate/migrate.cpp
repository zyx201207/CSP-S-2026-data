#include<bits/stdc++.h>
using namespace std;
int n,d,a[2000010];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int x,y;
	cin>>x>>y;
	while(y--) {
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if((a[2]-a[1])*2<=d) {
			int ans=d/(a[2]-a[1]);
			cout<<n-ans+1<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}
