//migrate
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,r[2000005];
int ccnt;
long long x[2000005],d;
int dfs(int pos,int l,int rr,int minn,int cnt)
{
	ccnt++;
	int ans=0;
	if(cnt>minn)
	{
		return ans;
	}
	if(x[rr]-x[pos]<=d)
	{
		ans++;
		return ans;
	}
	for(int i=pos+1;i<=r[pos];i++)
	{
		ans+=dfs(i,l,rr,minn,cnt+1);
	}
	return ans;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		int cntt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			r[i]=0;
		}
		if((c>=1)&&(c<=10))
		{
			for(int i=1;i<=n;i++)
			{
				r[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
				int ll=lower_bound(x+1,x+n+1,x[i]-d)-x;
				if(ll==r[i]) r[i]=0;
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					int cnt=0,aa=x[i],pos=i;
					if(r[j]!=0)
					{
						while(aa<x[j])
						{
							if(x[j]-aa<=d)
							{
								cnt++;
								break;
							}
							cnt++;
							pos=r[pos];
							aa=x[pos];
						}
						int res=dfs(i,i,j,cnt,0);
						if(res==2) cntt++;
					}
				}
			}
			cout<<cntt<<"\n";
		}
		else
		{
			if((x[2]-x[1]>=d)||(d>=x[n]-x[1])) cout<<"0\n";
			else
			{
				int maxt=d/(x[2]-x[1]);
				cout<<n-2*maxt+1<<"\n";
			}
		}
	}
	//cout<<ccnt;
	return 0;
}
/*
1 2 
5 3 
-2 -1 0 1 2 
6 2 
-4 -3 -2 -1 3 6 
*/
