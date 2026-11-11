#include<bits/stdc++.h>
using namespace std;
int c,t;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++) {
		int n,d;
		int ans=0;
		int x[20005];
		cin>>n>>d;
		for(int j=1;j<=n;j++) {
			cin>>x[j];
		}
		for(int j=1;j<=n;j++) {
			if(x[j+3]-x[j]>d) ans++;
		} 
		cout<<ans<<endl;
	}
	return 0;
}
