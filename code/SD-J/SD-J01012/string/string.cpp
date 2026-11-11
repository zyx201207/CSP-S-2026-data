#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,l,r,ans;
int z[N];
struct node
{
	int a;
	char c;
}x[N];
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i].a>>x[i].c;
		z[i]=z[i-1]+x[i].a;
	}
	for(int i=1;;i++)
	{
		l=r+1;
		r=z[i];
		if(l*2<=z[n]&&r*2>z[n]||l*2>=z[n])
		{
			break;
		}
		int rr=z[n]-l+1;
		int ll=z[n]-r+1;
		int l_=lower_bound(z+1,z+n+1,ll)-z;
		int r_=lower_bound(z+1,z+n+1,rr)-z;
		for(int j=l_;j<=r_;j++)
		{
			if(x[j].c==x[i].c)
			{
				continue;
			}
			if(j==l_)
			{
				if(z[l_]<rr)
				{
					ans+=z[l_]-ll+1;
				}
				else
				{
					ans+=rr-ll+1;
				}
			}
			else if(j==r_)
			{
				ans+=rr-z[r_-1];
			}
			else
			{
				ans+=z[j]-z[j-1];
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		int a;
//		char c;
//		cin>>a>>c;
//		while(a--)
//		{
//			s+=c;
//		}
//	}
//	s=" "+s;
//	int le=s.size();
//	for(int i=1;i<=le/2;i++)
//	{
//		int j=le-i;
//		if(s[i]!=s[j])
//		{
//			ans++;
//		}
//	}
	cout<<ans;
	return 0;
}
//I AK CSP-J!!!

