#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e+5;
int a[N];
int solve(int now,int m,int z)
{
	int sum=0;
	for(int i=now;i>=1;i--)
	{
		if(a[i]>z)
		continue;
		if(m-z+a[i]<0)
		return sum;
		else
		{
			sum++;
			m=m-z+a[i];
		}
	}
	return sum;
}
void deng(int m,int n)
{
	int sum=1,k=1;
	while(m>0&&sum<n)
	{
		if(m-k<0)
		break;
		sum++;
		m-=k;
		k++;
	}
	cout<<sum;
}
void cha(int m,int n,int s)
{
	int sum=1,k=s;
	while(m>0&&sum<n)
	{
		if(m-k<0)
		break;
		sum++;
		m-=k;
		k+=s;
	}
	cout<<sum;
}
signed main()
{
	int n,m;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i)
		flag=1;
	}
	for(int i=1;i<=n-2;i++)
	{
		if(a[i+1]-a[i]==a[i+2]-a[i-1])
		flag=2;
	}
	if(flag==0)
	{
		deng(m,n);
		return 0;
	}
	if(flag==2)
	{
		cha(m,n,a[2]-a[1]);
		return 0;
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int j=n;j>=1;j--)
	{
		int w=solve(j,m,a[j]);
		ans=max(ans,w);
	}
	cout<<ans;
	return 0;
 } 
