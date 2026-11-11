#include<bits/stdc++.h>
using namespace std;
long long n,a[200100],tot=0,ddd=0;
char s[200100];
struct node{
	long long a;
	char c;
}se[200100];
unsigned long long ret=0,ans=0;
int flag=0,id;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		ret+=a[i];
	}
	if(ret%2!=0)
	{
		flag=1;
	}
	ret/=2;
	for(int i=1;i<=n;i++)
	{
		ans+=a[i];
		if(ans<=ret)
		{
			se[++tot].a=a[i];
			se[tot].c=s[i];
		}
		else
		{
			long long g=ret-(ans-a[i]);
			se[++tot].a=g;
			se[tot].c=s[i];
			id=i;
			if(flag)
			{
				a[i]=a[i]-g-1;
			}
			else a[i]-=g;
			if(!a[i]) id++;
			break; 
		}
	}
	int but=0;
	for(int i=n;i>=id;i--)
	{
		while(a[i]>0)
		{
			but++;
			if(a[i]>=se[but].a)
			{
				if(se[but].c!=s[i])
				{
					ddd+=se[but].a;
				}
				a[i]-=se[but].a;
			}
			else
			{
				if(se[but].c!=s[i])
				{
					ddd+=a[i];
				}
				se[but].a-=a[i];
				a[i]=0;
				but--;
			}
		}
	}
	cout<<ddd;
	return 0;
}

