#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200050],l,tot;
string c[200050];
ll yyy;
int n1,n2;
ll s1[200050],s2[200050];
string c1[200050],c2[200050];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	ll i=0;
	while(i!=l/2)
	{
		n1++;
		if(a[n1]+i<=l/2)
		{
			s1[n1]=a[n1];
			c1[n1]=c[n1];
			i+=a[n1];
		}else{
			s1[n1]=l/2-i;
			c1[n1]=c[n1];
			i=l/2;
		}
	}
	i=0;
	while(i!=l/2)
	{
		n2++;
		if(a[n-n2+1]+i<=l/2)
		{
			s2[n2]=a[n-n2+1];
			c2[n2]=c[n-n2+1];
			i+=a[n-n2+1];
		}else{
			s2[n2]=l/2-i;
			c2[n2]=c[n-n2+1];
			i=l/2;
		}
	}
	i=0;ll j1=1,j2=1;
	while(i!=l/2)
	{
		if(s1[j1]==s2[j2])
		{
			if(c1[j1]!=c2[j2])
			{
				tot+=s1[j1];	
			}
			i+=s1[j1];j1++;j2++;
		}
		else if(s1[j1]<s2[j2])
		{
			if(c1[j1]!=c2[j2])
			{
				tot+=s1[j1];	
			}
			s2[j2]-=s1[j1];i+=s1[j1];j1++;
		}
		else if(s1[j1]>s2[j2])
		{
			if(c1[j1]!=c2[j2])
			{
				tot+=s2[j2];	
			}
			s1[j1]-=s2[j2];i+=s2[j2];j2++;
		}
//		cout<<i<<' '<<j1<<' '<<j2<<'\n';
	}
	cout<<tot;
}
