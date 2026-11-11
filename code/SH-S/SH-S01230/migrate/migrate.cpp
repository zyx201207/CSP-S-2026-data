#include<bits/stdc++.h>
using namespace std;
int c,w;
long long n,d;
long long a[2000005];
long long ans=0;
long long q[2000005];
long long t[2000005];
long long l,r;
long long cnt=0,st=0;
long long be=0,en=0;
bool fl=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>w;
	while(w--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			q[i]=0;
			t[i]=0;
		}
		for(int i=1;i<n;i++)
		{
			l=i-1,r=n+1;
			while(l+1<r)
			{
				long long mid=(l+r)/2;
				if(a[mid]-a[i]<=d)
				{
					l=mid;
				}
				else
				{
					r=mid;
				}
			}
			q[i]=l;
		}
		q[n]=1e6;
		for(int i=1;i<=n;i++)
		{
			if(q[i]==i+1&&!fl&&q[i-1]<=i)
			{
				fl=1;
				cnt=1;
				st=i;
			}
			else if(q[i]!=i+1&&fl)
			{
				fl=0;
				t[st]=cnt;
				t[i-1]=cnt;
				cnt=0;
			}
			else if(q[i]==i+1&&fl)
			{
				cnt++;
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<q[i]<<" ";
//		}
//		cout<<endl;
//		for(int i=1;i<=n;i++)
//		{
//			cout<<t[i]<<" ";
//		}
//		cout<<endl;
		ans=0;
		for(int i=2;i<=n-2;i++)
		{
//			cout<<a[i+2]-a[i-1]<<" "<<a[i+1]-a[i-1]<<" "<<a[i+2]-a[i]<<endl;
			if(a[i+2]-a[i-1]>d&&a[i+1]-a[i-1]<=d&&a[i+2]-a[i]<=d)
//			if(q[i]==q[i+1]&&q[i]==q[i-1]+1)
			{
				l=0,r=i+1;
				while(l+1<r)
				{
					long long mid=(l+r)/2;
					if(q[mid]==q[i-1])
					{
						r=mid;
					}
					else
					{
						l=mid;
					}
				}
				ans+=(q[i]-i-1+t[q[i]])*(i-1-r+t[r-1]+1);
//				cout<<(q[i]-i-1+t[q[i]])<<" "<<(i-1-r+t[r-1]+1)<<endl;
			}
		}
//		cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
} 
/*
0 1
6 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 200000000000000000 600000000000000000 1000000000000000000
2026/10/31,18:29 
*/

