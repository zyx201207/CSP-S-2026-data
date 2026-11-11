#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],p,s=1,sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=(1<<30);i>=1;i/=2)
	{
		p=lower_bound(a+s,a+n+1,i)-a;
		if(n-p+1>=m) sum+=i,s=p;
		for(int j=p;j<=n;j++) a[j]%=i;
		sort(a+p,a+n+1);
	}
	cout<<sum;
	return 0;
}