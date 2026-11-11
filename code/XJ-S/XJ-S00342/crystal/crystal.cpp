#include<bits/stdc++.h> 
using namespace std;
const int N=1e5*5+5;
int a[N],b[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,i,j,k,Max=-1;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		int x=0; 
		for(j=1;j<=n;j++)
		{
			b[++x]=abs(a[i]-a[j]);
		}
		sort(b+1,b+x+1);
		int t=m,ans=0;
		while(1)
		{
			j++; 
			if(t-b[j]>=0)
			{
				ans++;
			}
			else break;
		}
		Max=max(Max,ans);
	}
	cout<<Max;
	return 0;
}
