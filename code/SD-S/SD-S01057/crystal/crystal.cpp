#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
const int M=1e9;
int n,m,flag=1;
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int x=m;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	} 
	for(int i=1;i<=n;i++)
    {
    	if(a[i]!=i)
    	{
    		flag=0;
    		break;
		}
	}
	int d=sum/n;
	if(flag==1)
	{	
	    int ans=1;
		for(int i=1;i<d;i++)
		{
			if(m==0)
			{
				break;
			}
			if(m>=abs(a[i]-d))
			{
				m-=abs(a[i]-d);
				ans++;
			}
			else if(m<abs(a[i]-d))
			{
				break;
			}
		}
		if(m>0)
		{
			if(m>ans)
			{
			   int j=x/ans;
			   ans+=j-1;
			   cout<<ans;
			   return 0;
			}
			else if(m==ans)
			{
				cout<<ans+1;
				return 0;
			}
			else if(m<ans)
			{
				cout<<ans;
				return 0;
			}
		}
		else if(m==0)
		{
			cout<<ans;
			return 0;
		}
	}
	else
	{
		int minn=M;
		int z;
		int cnt=0;
	    for(int i=1;i<=n;i++)
	    {
	    	if(abs(a[i]-d)<minn)
	    	{
	    		minn=abs(a[i]-d);
	    		z=i;
			}
		}
		int p=z;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[p])
			{
				cnt++;
			}
		}
		for(int i=1;i<z;i++)
		{
			if(m>0)
			{
				if(m>=abs(a[i]-a[p]))
				{
					m-=abs(a[i]-a[p]);
			        cnt++;
				}
			}
			else
			{
				break;
			}
		}
		cout<<cnt;
	}
	return 0;
}
