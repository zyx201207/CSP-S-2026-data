#include<bits/stdc++.h>
using namespace std;
const int MX=2e5;
struct node
{
	long long ge;
	char ch;
}a[MX+10];
long long n;
long long s; 
long long sum=0;
inline long long read()
{
	char ch=getchar();
	long long x=0,f=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	n=read();
	int i;
	for(i=1;i<=n;i++)
	{
		a[i].ge=read();
		cin>>a[i].ch;
		s+=a[i].ge;
	}
	long long l=1,r=s,pl=1,ppl=0,ppr=0,pr=n;
	while(l<r)//»ãºÏ
	{
		if(a[pl].ch!=a[pr].ch)
		{
			sum+=min(a[pl].ge-ppl,a[pr].ge-ppr);
			l+=min(a[pl].ge-ppl,a[pr].ge-ppr);
			r-=min(a[pl].ge-ppl,a[pr].ge-ppr);
			if(a[pl].ge-ppl>a[pr].ge-ppr)
			{
				
				ppl+=a[pr].ge-ppr;
				pr--;
				ppr=0;
			}
			else if(a[pl].ge-ppl<a[pr].ge-ppr)
			{
				
				ppr+=a[pl].ge-ppl;
				pl++;
				ppl=0;
			}
			else
			{
				pl++;
				pr--;
				ppl=ppr=0;
			}
		}
		else
		{
			l+=min(a[pl].ge-ppl,a[pr].ge-ppr);
			r-=min(a[pl].ge-ppl,a[pr].ge-ppr);
			if(a[pl].ge-ppl>a[pr].ge-ppr)
			{
				
				ppl+=a[pr].ge-ppr;
				pr--;
				ppr=0;
			}
			else if(a[pl].ge-ppl<a[pr].ge-ppr)
			{
				
				ppr+=a[pl].ge-ppl;
				pl++;
				ppl=0;
			}
			else
			{
				pl++;
				pr--;
				ppl=ppr=0;
			}
		}
	} 
	cout<<sum<<'\n';
	return 0;
}
