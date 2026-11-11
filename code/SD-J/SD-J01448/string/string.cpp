#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,l=1,r,ans; 
struct zzz
{
	long long a;
	char b;
}k[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i].a>>k[i].b;
	}
	r=n;
	while(l<=r)
	{
		if(k[l].b==k[r].b)
		{
			if(k[l].a==k[r].a)
			{
				l++,r--;
			}
			else if(k[l].a>k[r].a)
			{
				k[l].a-=k[r].a;
				r--;
			}
			else if(k[l].a<k[r].a)
			{
				k[r].a-=k[l].a;
				l++;
			}
		}
		else
		{
			if(k[l].a==k[r].a)
			{
				ans+=k[l].a;
				l++,r--;
			}
			else if(k[l].a>k[r].a)
			{
				ans+=k[r].a;
				k[l].a-=k[r].a;
				r--;
			}
			else if(k[l].a<k[r].a)
			{
				ans+=k[l].a;
				k[r].a-=k[l].a;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
} 

