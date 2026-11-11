#include<bits/stdc++.h>
using namespace std;
bool xx(long long a,long long b)
{
	return a>b;
}
int xxx(long long a)
{
	int ans1=1;
	while(a!=1)
	{
		a/=2;
		ans1*=2;
	}
	return ans1;
}
int main()
{
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int ans=0;
	cin>>n>>m;
	long long a[200010];
	 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,xx);
	int d=xxx(a[1]);
	ans=dp2;
	int dp2=d*2-1;
	int ans2=d;
	int c=0;
	
	
	while(d!=1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>ans&&(a[i]&dp2)>d)
			{
				c+=1;
				ans=ans&a[i];
			}
				 
		}
		if(d==1)break;
		if(c==m)break;
		else if(c>m)
		{
		
			dp2=(dp2+1)/2-1;
			d=(d+1)/2-1;
			
		}
		else
		{
			dp2=(dp2+1)/2-1;
			d=(d+1)/2-1;
		
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 
