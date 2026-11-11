#include<bits/stdc++.h>
using namespace std;
struct ch{
	long long id;
	char s;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].id>>a[i].s;
	}
	int l=1,r=n;
	long long ans=0;
	while(r!=l&&l<r)
	{
		if(a[l].s==a[r].s)
		{
			if(a[l].id>a[r].id)
			{
			    a[l].id-=a[r].id;
				r--;
			}
			else if(a[l].id==a[r].id)
			{
				r--;
				l++;
			}
			else
			{
				a[r].id-=a[l].id;
				l++;
			}
		}
		else
		{
			if(a[l].id>a[r].id)
			{
			    ans+=a[r].id;
				a[l].id-=a[r].id;
				r--;
			}
			else if(a[l].id==a[r].id)
			{
				ans+=a[r].id;
				r--;
				l++;
			}
			else
			{
				ans+=a[l].id;
				a[r].id-=a[l].id;
				l++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
