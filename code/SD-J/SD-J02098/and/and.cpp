#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[200005],b[200005];
int n,k,t,tot;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int x=a[i],ans=0;
		while(x)
		{
			x/=2;
			ans++;
			b[ans]++;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=50;i++)
	{
		if(b[i]>=k)
		{
			t=i;
		}
	}
	for(int i=t;i>=t-k;i--)
	{
		tot=a[i]&tot;
	}
	cout<<tot<<endl;
	return 0;
}
