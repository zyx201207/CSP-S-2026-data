#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000005];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(long long j=1; j<=t; j++) {
		long long n,d;
		long long ans=0;
		cin>>n>>d;
		for(long long i=1; i<=n; i++)
			cin>>a[i];
		if(a[2]-a[1]>=d) cout<<0<<endl;
		else if(c==11||c==12) {
			for(int i=1; i<n; i++)
				for(int u=n; u>=i; u--) {
					if(a[3]-a[1]<=d) {
						if((u-i)%2==1&&i!=u&&abs(i-u)>2&&a[u]-a[i]>d) {
							ans++;
						}
					}
				}
			cout<<ans<<endl;
		}else cout<<0<<endl;
	}
	return 0;
}/*
11 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/ 
/*
嵊州市新城实验学校909 ZHY_LOVE_ZZQ
我洛谷号:yeweibo
*/
