#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,sum,a[N];
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r)
	{
		if(a[l]<a[r])
		{
			if(c[l]!=c[r])
			{
				sum+=a[l];
			}
			a[r]-=a[l];
			l++;	
		}
		else if(a[l]>a[r])
		{
			if(c[l]!=c[r])
			{
				sum+=a[r];
			}
			a[l]-=a[r];
			r--;
		} 
		else if(a[l]==a[r])
		{
			if(c[l]!=c[r])
			{
				sum+=a[r];
			}
			l++;
			r--;	
		}
	}
	cout<<sum;
	return 0;
}
