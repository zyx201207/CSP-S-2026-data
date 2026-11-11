#include <bits/stdc++.h>
using namespace std;
long long s=0,s1,s2=0,a[100000],a1=1,j=1,k,i,judge1,judge2;
string c[100000],c1[100000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		s+=a[i];
	}
	//cout<<s;
	for(i=1;i<=s;i++)
	{
		
		if(a1<a[j])
		{
			c1[i]=c[j];
			a1++;
		}
		else
		{
			a1=1;
			c1[i]=c[j];
			j++;
		}
	}
	/*for(int i=1;i<=s;i++)
	cout<<c1[i];*/
	s1=s;
	s/=2;
	
	for(i=1;i<=s1/2;i++)
	{
		if(c1[i]==c1[s1+1-i])
		{
			for(j=1;j<=n;j++)
			{
				
				if(c[j]==c1[i]&&i>=s2&&i<=s2+a[j])
				{
					judge1=a[j];
					break;
				}
				s2+=a[j];
			}
			s2=s1;
			for(k=n;k>=1;k--)
			{
				
				if(c[k]==c1[i]&&i<=s2&&i>=s2-a[k])
				{
					judge2=a[k];
					break;
				}
				s2-=a[k];
			}
			s2=0;
			if(judge1>judge2)
			{
				s-=a[k];
				i+=a[k];
			}
			else
			{
				s-=a[j];
				i+=a[k];
			}
		}
		if(c1[i]!=c1[s1+1-i])
		{
			for(j=1;j<=n;j++)
			{
				
				if(c[j]==c1[i]&&i>=s2&&i<=s2+a[j])
				{
					judge1=a[j];
					break;
				}
				s2+=a[j];
			}
			s2=s;
			for(k=n;k>=1;k--)
			{
				
				if(c[k]==c1[i]&&i<=s2&&i>=s2-a[k])
				{
					judge2=a[k];
					break;
				}
				s2-=a[k];
			}
			s2=0;
			if(judge1>judge2)
			i+=a[k];
			else
			i+=a[k];
		}
	}
	cout<<s;
	return 0;
}
