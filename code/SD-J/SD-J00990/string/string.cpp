#include <bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	long long ans=0;
	cin >> n;
	for(int i=1;i<=n;++i)
	{
	    cin >> a[i];
	    cin >> c[i];
	}
	long long l=1;
	long long r=n;
	while(l<=r)
	{
		if(!(c[l]==c[r]))
		{
		    if(a[l]>a[r])
		    {
		    	ans += a[r];
		    	a[l]-=a[r];
		    	--r;
			}
			else if(a[l]<a[r])
			{
				ans += a[l];
				a[r]-=a[l];
				++l;
			}
			else
			{
				ans += a[l];
				++l;
				--r;
			}
		}
		else
		{
		    ++l;
			--r;
		}
	}
	cout << ans;
	return 0;
}
