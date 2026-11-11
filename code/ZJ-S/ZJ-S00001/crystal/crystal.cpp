#include<bits/stdc++.h>
using namespace std;
const int MN=5e5+5;
long long s[MN],a[MN],n,m,ans=1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++)
		s[i]=s[i-1]+a[i];
	int p=0;
	for(int i=1; i<=n; i++) {
		while(a[i]*(i-p)-s[i]>m&&p<i)++p;
	//	cout<<a[i]<<" "<<s[i]<<" ";
	//	cout<<i<<" "<<p<<"---\n";
		long long cnt=i-p;
		ans=max(ans,cnt);
	//	cout<<cnt<<"cnt\n";
	}
	cout<<ans;
	return 0;
}
