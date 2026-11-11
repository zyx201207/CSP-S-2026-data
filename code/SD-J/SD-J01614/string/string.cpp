#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5;
struct node
{
	long long l;
	char s;
}a[N+5];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0,lth=0,nth=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].l>>a[i].s;
		lth+=a[i].l;
	}
	long long last=n;
	for(int i=1;i<=n;i++)
	{
		if(nth>=lth/2) break;
		if(nth+a[i].l>lth/2) a[i].l-=nth+a[i].l-lth/2;
		long long sum=0;
		for(int j=last;j>i;j--)
		{
			if(sum+a[j].l==a[i].l)
			{
				if(a[j].s!=a[i].s) cnt+=a[j].l;
				last=j-1; 
				break;
			}
			else if(sum+a[j].l>a[i].l)
			{
				if(a[j].s!=a[i].s) cnt+=a[j].l-((sum+a[j].l)-a[i].l);//so many bugs QWQ;	 
				a[j].l=sum+a[j].l-a[i].l;
				last=j;
				break;
			}
			if(a[j].s!=a[i].s) cnt+=a[j].l;
			sum+=a[j].l;
		}
		nth+=a[i].l;
	}
	cout<<cnt; 
	return 0;
}
