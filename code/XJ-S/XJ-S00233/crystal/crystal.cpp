#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500005],sum,cnt,maxn,ans,base=1,zhyw,back,pp,dc;
bool flag=1,flak=1;
bool cmp (int x,int y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]!=i)flag=0;
		zhyw+=a[i];
    }
	sort (a+1,a+n+1,cmp);
	if(n<=5020)
	{ 
		for (int i=1;i<=n;i++)
		{
			cnt=m;
			ans=0;
			for (int j=i;j>=1;j--)
			{
			//枚举a[i]为合成点 进行打爆力 
			if(a[j]==a[i])ans++;
			if(a[j]<a[i])
			{
				if(cnt>=(a[i]-a[j]))
				{
					ans++;
					cnt-=a[i]-a[j];
				}
				else break;
			 }
			}
			maxn=max(maxn,ans);
		}
		cout<<maxn;
	}
	else if(flag==1)
	{
		base=1;
		for (int i=2;i<=n;i++)
		{   
		sum+=base;//1 2 3 4 5
		base+=i-1;
		if(sum>m)
		{
			cout<<i-1;
			return 0;
		}
		else if(sum==m)
		{
			cout<<i;
			return 0;
		}
		//0 1 2 4 7 15 21
			//1 2 3 4 5 6  7 8 9 
			// 8
		}
	}
	else if(a[2]-a[1]==a[3]-a[2]&&a[4]-a[3]==a[3]-a[2]) 
	{
		dc=a[2]-a[1];
		for (int i=2;i<=n;i++)
		{
			if(a[i]-a[i-1]!=dc)
			{
				flak=0;
				break;
			}
		}
		if(flak==1)
		{
			base=dc;
			for (int i=2;i<=n;i++)
			{   
				sum+=base;
				base+=dc*(i-1);//1 3 5 7 9  8 dc*i-1
				if(sum>m)
				{
					cout<<i-1;
					return 0;
				}
				else if(sum==m)
				{
					cout<<i;
	        		return 0;
				}
			}	
		}
	}
	else 
	{
		back=zhyw/n;
		for (int i=n;i>=1;i--)
		{
			if(i<=back)
			{
			cout<<i;
		    return 0;
			}
     	}
	}
	return 0; 
}
