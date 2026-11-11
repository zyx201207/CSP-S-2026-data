#include<bits\stdc++.h>
using namespace std;
unsigned long long int t,ans;
struct zc
{
	long long int qj;
	char c;
}a[200005];
int n,l,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n-1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].qj>>a[i].c;
	}
	while(l<=r)
	{
		if(a[l].c==a[r].c)
		{
			t=a[l].qj-a[r].qj;
			if(t==0)
			{
				l++,r--;
			}
			else if(t>0)
			{
				r--;
				a[l].qj=t;
			}
			else
			{
				l++;
				a[r].qj=abs(t);
			}
		}
		else
		{
			t=a[l].qj-a[r].qj;
			if(t==0)
			{
				ans+=abs(a[l].qj);
				l++,r--;
			}
			else if(t>0)
			{
				ans+=abs(a[r].qj);
				r--;
				a[l].qj=t;
			}
			else
			{
				ans+=abs(a[l].qj);
				l++;
				a[r].qj=abs(t);
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
