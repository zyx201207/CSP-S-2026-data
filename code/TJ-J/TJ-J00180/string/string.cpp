#include <bits/stdc++.h>
using namespace std;
long long n,a[1000000],b[1000000],l,r,ans,o;
char s;
int main()
{
	//==============================================
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> s;
		b[i]=s-'a';
	}
	l=1;
	r=n;
	while(l<r)
	{
		if(b[l]!=b[r])
		{
			ans+=min(a[l],a[r]); 
			a[l]=max(a[l]-a[r],o);
			a[r]=max(a[r]-a[l],o);
		}
		else
		{
			a[l]=max(a[l]-a[r],o);
			a[r]=max(a[r]-a[l],o);
		}
		if(a[l]==0)
		{
			l++;
		}
		if(a[r]==0)
		{
			r--;
		}
	}
	cout << ans;
	return 0;
}
