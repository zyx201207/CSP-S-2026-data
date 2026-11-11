#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],ans1,ans2;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(m==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n&&j!=i;j++)
				ans1=max(a[i]&a[j],ans1);
	}
	sort(a+1,a+n+1,cmp);
	ans2=a[1];
	for(int i=2;i<=m;i++)
		ans2=a[i]&ans2;
	cout<<max(ans1,ans2);
	return 0;
}
