#include<bits/stdc++.h>
using namespace std;
const int w=500005;
long long n,ans=-1;
long long a[w];
unsigned long long m;
long long cha[5005][5005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	memset(cha,0,sizeof(cha));
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)cin>>a[i]; 
	sort(a+1,a+1+n);
	if((a[n]-a[1])*n<=m)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			cha[i][j]=a[j]-a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=i+1;j--)
		{
			int cost=0;
			for(int k=i;k<=j;k++)
			{	
				cost+=cha[k][j];
				if(cost>m)break;
			}
			long long r=j+1-i;
			if(cost<=m&&r>ans)ans=r;
			else if(cost<=m&&r<=ans)break;
		}
	}
	cout<<ans;
	return 0;
}
/*
7 8100
1 4 7 9 14 17 18
*/

