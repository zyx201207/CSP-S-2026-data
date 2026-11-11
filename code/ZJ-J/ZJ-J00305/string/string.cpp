#include<bits/stdc++.h>
using namespace std;
const int N=200005;
struct node{
	long long a;
	char ch;
};
node a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i,l,r;
	long long cnt;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].ch;
	}
	l=1;
	r=n;
	cnt=0;
	while(l<r)
	{
		if(a[l].a<a[r].a)
		{
			a[r].a-=a[l].a;
			if(a[l].ch==a[r].ch)
			{
				a[l].a=0;
			}
			else
			{
				cnt+=a[l].a;
				a[l].a=0;
			}
		}
		else
		{
			a[l].a-=a[r].a;
			if(a[l].ch==a[r].ch)
			{
				a[r].a=0;
			}
			else
			{
				cnt+=a[r].a;
				a[r].a=0;
			}
		}
		if(a[l].a==0)
		{
			l++;
		}
		if(a[r].a==0)
		{
			r--;
		}
	}
	cout<<cnt;
	return 0;
}