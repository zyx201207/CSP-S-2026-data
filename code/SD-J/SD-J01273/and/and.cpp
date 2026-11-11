#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N],Max;
long long l[N];
int f[N];
bool o(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int g=a[i];
		int j=1;
		while(g!=0)
		{
			l[j]*=10;
			l[j]+=g%2;
			g/=2;
			j++;
		}
	}
	int t=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			long long h1=l[i],h2=l[j];
			int h=1;
			for(int k=1;k<=n;k++)
			{
				f[t]+=(h1%10)*(h2%10)*h;
				h1/=10;
				h2/=10;
				h*=2;
			}
			t++;
		}
	}
	sort(f+1,f+t,o);
	for(int i=1;i<=n;i++)
	{
		Max=max(f[i],Max);
	}
	cout<<Max;
	return 0;
}
