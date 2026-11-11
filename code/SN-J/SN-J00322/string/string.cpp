#include<bits/stdc++.h>
using namespace std;
long long n,d,ans;
char c;
struct A
{
	long long st,ed;
	char a;
} a[200005],b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>d>>c;
		a[i].st=a[i-1].ed+1;
		a[i].ed=a[i-1].ed+d;
		a[i].a=c;
	}
	for(int i=1;i<=n;i++)
	{
		b[i].a=a[n-i+1].a;
		b[i].st=b[i-1].ed+1;
		b[i].ed=b[i-1].ed+a[n-i+1].ed-a[n-i+1].st+1;
	}
	long long si=a[n].ed,md=si/2;
	/*
	for(int i=1;i<=n;i++)
	{
		cout<<a[i].st<<" "<<a[i].ed<<" "<<a[i].a<<"\n";
	}
	cout<<"\n\n";
	for(int i=1;i<=n;i++)
	{
		cout<<b[i].st<<" "<<b[i].ed<<" "<<b[i].a<<"\n";
	}
	cout<<"\n";
	*/
	for(int i=1;i<=n;i++)
	{
		if(a[i].st<=md&&a[i].ed>=md)
		{
			a[i].ed=md;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i].st<=md&&b[i].ed>=md)
		{
			b[i].ed=md;
			break;
		}
	}
	for(int i=1,j=1;i<=n&&j<=n;)
	{
		if(a[i].ed>b[j].ed)
		{
			if(a[i].a!=b[j].a)
			{
				ans+=b[n-j+1].ed-max(a[n-i+1].st,b[n-j+1].st)+1;
			}
			j++;
		}
		if(a[i].ed<b[j].ed)
		{
			if(a[i].a!=b[j].a)
			{
				ans+=a[n-i+1].ed-max(a[n-i+1].st,b[n-j+1].st)+1;
			}
			i++;
		}
		if(a[i].ed==b[j].ed)
		{
			if(a[i].a!=b[j].a)
			{
				ans+=a[n-i+1].ed-max(a[n-i+1].st,b[n-j+1].st)+1;
			}
			if(a[i].ed==md)
			{
				break;
			}
			else
			{
				i++;j++;
			}
		}
	}
	cout<<ans;
	
	return 0;
} 

