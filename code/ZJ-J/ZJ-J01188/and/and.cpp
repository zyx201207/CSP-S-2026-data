#include<bits/stdc++.h>
using namespace std;
string f1(int n)
{
	string s="",c="";
	for(int i=n;i>0;i/=2)
		s+=(i%2+'0');
	int l=s.size();
	for(int i=0;i<l;i++)
		c+=s[l-i-1]; 
	return c;
}
int f2(string s1,string s2)
{
	string s="";
	int l1=s1.size(),l2=s2.size();
	int l=min(l1,l2);
	for(int i=l;i>=1;i--)
		if(s1[l1-i]=='1'&&s2[l2-i]=='1')
			s+='1';
		else
			s+='0';
	int ll=s.size(),sum=0,t=1;
	for(int i=ll-1;i>=0;i--)
	{
		if(s[i]=='1')
			sum+=t;
		t*=2;
	}
	return sum;
}
int a[20005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
		cin>>a[i];
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	if(m==2)
	{
		int x=-1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				x=max(f2(f1(a[i]),f1(a[j])),x);
		cout<<x;
	}
	if(m==n)
	{
		int p=f2(f1(a[1]),f1(a[2]));
		for(int i=3;i<=n;i++)
			p=f2(f1(a[i]),f1(p));
		cout<<p;
	}
	if(m==n-1)
	{	
		int maxx=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;i<n;j++)
				if(j!=i&&j+1!=i)
					maxx=max(f2(f1(a[j]),f1(a[j+1])),maxx); 
		}
		cout<<maxx;
	}
	return 0;
}
