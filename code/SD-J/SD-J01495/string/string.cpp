#include<bits/stdc++.h>
using namespace std;
int n;
struct str
{
	long long a;
	char c;
}aa[200005];
long long s;
long long lena;
int l,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>aa[i].a>>aa[i].c;
		lena+=aa[i].a;
	}
	lena=(lena+1)/2;
	l=1,r=n;
	while(l<r)
	{
		if(aa[l].c!=aa[r].c)
		{
			s+=min(aa[l].a,aa[r].a);
			if(aa[l].a>aa[r].a)
			{
				aa[l].a-=aa[r].a;
				r--;
			}
			else if(aa[l].a==aa[r].a)
			{
				l++,r--;
			}
			else
			{
				aa[r].a-=aa[l].a;
				l++;
			}
		}
		else
		{
			if(aa[l].a>aa[r].a)
			{
				aa[l].a-=aa[r].a;
				r--;
			}
			else if(aa[l].a==aa[r].a)
			{
				l++,r--;
			}
			else
			{
				aa[r].a-=aa[l].a;
				l++;
			}
		}
	}
	cout<<s;
	return 0;
}
