#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long m,a[500000],ans=0;
void dfs(long long b,int j,long long num)//可加多少；离max多少；第几个 
{
	if(j-num<0)
	{
		ans=max(num,ans); 
		return;
	}
	b=b-(a[j]-a[j-num]);
	if(b>=0)
	{
		num+=1;
		dfs(b,j,num);
	}
	else 
	{
		ans=max(num,ans);
		return;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,i,j,ama=0;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(&a[0],&a[0]+n);
	bool c=true;
	for(i=0;i<n-1;i++)
		{
			if(ama!=a[i+1]-a[i])c=false;
			ama=max(ama,a[i+1]-a[i]);
		}
	if(c&&n>=5000&&n<=500000&&m>=100000000&&m<=1000000000000000000)
	{
		if(ama==1)
		{
			ans=m/2+m%2;
		}
		else
		{
			m/=ama;
			ans=m/2+m%2;
		}
	}
	else
	{
		ans=0;
		for(i=0;i<n;i++)
		{
			dfs(m,i,0);
		}
	}
	cout<<ans;
    return 0;	
} 
