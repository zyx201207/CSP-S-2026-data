#include <bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long a[N];
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,greater<long long>());
	long long sum=a[0];
	for(int i=0;i<m;i++) sum&=a[i];
	cout<<sum; 
}	
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
}
