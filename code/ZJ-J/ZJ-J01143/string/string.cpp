#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],cnt=0;
char c[20010];
struct node{
	long long s;
	char b;
};
node l,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l1=1,r1=n;

	while(l1<r1)
	{
		if(l.s>r.s)
		{
			
			if(l.b!=c[r1])
			{
				cnt+=min(l.s,a[r1]);
				if(l.s>=a[r1])
				{
					l.s-=a[r1];
				}
				else 
				{
					r.s+=a[r1]-l.s;
					r.b=c[r1];
					l.s=0;
				}
				r1--;
			}
			else 
			{
				r.s+=a[r1];
				r.b=c[r1];
			}
			l.s-=r.s;
			r.s=0;
		}
		else if(l.s<r.s)
		{
			
			if(r.b!=c[l1])
			{
				cnt+=min(r.s,a[l1]);
				if(r.s>=a[l1])
				{
					r.s-=a[l1];
				}
				else 
				{
					l.s+=a[l1]-r.s;
					l.b=c[l1];
					r.s=0;
				}
				l1++;
			}
			else 
			{
				l.s+=a[l1];
				l.b=c[l1];
			}
			r.s-=l.s;
			l.s=0;
		}
		//aaa aaa
		if(c[l1]==c[r1])
		{
			if(a[l1]>=a[r1])
			{
				l.s+=a[l1]-a[r1];
				l.b=c[l1];
			}
			else 
			{
				r.s+=a[r1]-a[l1];
				r.b=c[l1];
			}
			l1++;
			r1--;
		}
			// aaa bbb
		else
		{
			cnt+=min(a[l1],a[r1]);
			if(a[l1]>=a[r1])
			{
				l.s+=a[l1]-a[r1];
				l.b=c[l1];
			}
			else 
			{
				r.s+=a[r1]-a[l1];
				r.b=c[r1];
			}
			l1++;
			r1--;
		}
	}
	if(l1==r1)
	{
		if(l.s>=r.s)
		{
			l.s-=r.s;
			r.s=0;
		}
		else
		{
			r.s-=l.s;
			l.s=0;
		}
		long long s1=abs(l.s-r.s)+a[l1];
		if(s1%2==0)
		{
			s1/=2;
			if(l.s>r.s)cnt+=min(l.s,s1);
			else cnt+=min(r.s,s1);
		}
		else
		{
			s1=(s1-1)/2;
			if(l.s>r.s)cnt+=min(l.s,s1);
			else cnt+=min(r.s,s1);
		}
	}
	cout<<cnt;
	return 0;
}

