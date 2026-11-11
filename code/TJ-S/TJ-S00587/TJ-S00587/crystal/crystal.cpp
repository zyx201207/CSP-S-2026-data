#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long m,a[N],k=1,n,ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	long long p=abs(a[2]-a[1]);
	for(long long i=2;i<=n;i+=p)
	{
		if(k<=m) ans++;
		else break;
		k+=i;
	}
	cout<<min(ans,n);
	return 0;
}
