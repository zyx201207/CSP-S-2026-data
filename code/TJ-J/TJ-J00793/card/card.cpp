#include<bits/stdc++.h>
using namespace std;
long long const MAXN=5e5+5;
long long n,m,a[MAXN],b[MAXN],s[MAXN]{};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=n;i++)
	{
		long long tg=i-1;
		for(long long j=1+tg;j<=n;j++)
		{
			b[j]=a[j];
			for(long long p=1+tg;p<j;p++)
			{
				if(b[j]==b[p])
				{
					for(long long q=p;q<=n;q++) b[q]=0;
					b[j]=a[j];
				}
			}
		}
		for(long long j=1+tg;j<=n;j++)
		{
			if(b[j]>0) s[b[j]]++;
			b[j]=0;
		}
	}
	for(long long j=1;j<=m;j++) cout<<s[j]<<' ';
	return 0;
}
