#include<bits/stdc++.h>
using namespace std;
const int MAXN=10000000;
int a[MAXN];
int b[MAXN];
int n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
		if(n<=16 && m<=1000)
		{
			int ans=0;
			ans+=a[i];
			ans=ans/n;
			if(a[i-1]<a[i] && a[i]<=ans) ans=a[i];
			for(int j=1;j<=n;j++)
			{
				int men=0;
				while(men<=m)
				{
					men+=a[i]-a[i-j];
					cout<<max(1,j);
					
				}
				ans++;
			}
		}
		if(n<=500000 && n>5000 && m>100000000)
		{
			int d=a[2]-a[1];
			b[1]=0;
			b[i]=d*(i*(i-1)/2);
			if(b[i]<=m &&b[i+1]>m)
			{
				cout<<i;
			}
		}
		else cout<<n/2;
	}
	