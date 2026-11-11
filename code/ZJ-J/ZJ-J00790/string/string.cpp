#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],b[N],ans;
char c1[N],c2[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c1[i];
		b[n-i+1]=a[i];
		c2[n-i+1]=c1[i];
	}
	int l=1,r=1;
	while(l<=n&&r<=n)
	{
		if(a[l]>=b[r])
		{
			if(c1[l]==c2[r])
			{
				a[l]-=b[r];
				r++;
			}
			else
			{
				a[l]-=b[r];
				ans+=b[r];
				r++;
			}
		}
		else
		{
			if(c1[l]==c2[r])
			{
				b[r]-=a[l];
				l++;
			}
			else
			{
				b[r]-=a[l];
				ans+=a[l];
				l++;
			}
		}
	}
	cout<<ans/2;
}
