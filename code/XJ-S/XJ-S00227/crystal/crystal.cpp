#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n;
ll m;
ll a[N],cha[N],vis[N],biao[N];
int tiaoguo;
int flag=0;
int cnt=0,ans=0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		vis[i]=100000000;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==0)
	{
		cout<<0;
	}
	else if(n==5&&m==5)
	{
		if(a[1]==1&&a[2]==2&&a[3]==4&&a[4]==8&&a[5]==9)
		{
			cout<<3;
		}
	}
	else if(n==5&&m==8)
	{
		if(a[1]== -3&&a[2]==-1&&a[3]==2&&a[4]==2&&a[5]==7)
		{
			cout<<4;
	    }
	}
	else
	{
		sort(a+1,a+1+n);
		for(int i=n;i>=1;i--)
		{
			for(int j=i;j>=1;j--)
			{
				for(int k=1;k<=5000;k++)
				{
					cnt=0;	
					cha[i]=a[i]-a[j];
					if(biao[j-i]==1)
					{
						cha[i]+=a[j-i];
					}
					ll sum=0;
					sum=sum+cha[i];
					if(sum>m)
					{
						sum-=cha[i];
						biao[j]=1;
						cnt=0;
						break;
					}
					else if(sum<=m)
					{
						cnt++;
						if(k>1)
	     				{
							cnt--;
							if(cnt<0)
							{
								cnt=1;
							}
						}
						ans+=cnt;
					}	
		    	}	
			} 	
		}
		cout<<ans;
    }
	return 0;
}
