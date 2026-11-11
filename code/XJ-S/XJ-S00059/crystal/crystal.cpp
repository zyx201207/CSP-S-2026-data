#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500002];
long long int cnt,ans;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		long long int cnt=0,c=0;
		long long int p=m;
		for(int j=i; j>=1; j--) {
			if(a[i]-a[j]>p) break;
			c=a[i]-a[j];
			p-=c;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
