#include<bits/stdc++.h>
using namespace std;
long long f1[2000005],f2[2000005],f3[2000005],a[2000005],l[2000005],ans;
void chg(int n,long long d)
{
	int y=1;
	for(int i=1;i<=n;i++)
	{
		while(a[i]-a[y]>d) y++;
		l[i]=y;
	}
	for(int i=1;i<=n;i++)
	{
		if(i-l[i]+1==1)
		{
			f1[i]=0;
		}
		else if(i-l[i]+1==2)
		{
			f1[i]=f1[i-1];
		}
		else if(i-l[i]+1==3)
		{
			int p1=l[i-2],p2=l[i-1];
			if(p1==p2)
			{
				f1[i]=f2[i-2]+i-2-p1;
			}
			else
			{
				if(p2-p1==1)
				{
					if(p2>=i-2)
					{
						f1[i]=f1[i-2];
					}
					else
					{
						f1[i]=f3[p2]+i-2-p2;
					}
				}
				else
				{
					if(p2>=i-2)
					{
						f1[i]=f1[i-2];
					}
					else
					{
						f1[i]=f1[i-2]+i-2-p2;
					}
				}
			}
		}
		else
		{
			int p1=l[i],p2=p1+1,p3=p2+1;
			p1=l[p1],p2=l[p2],p3=l[p3];
			if(p1>=l[i])
			{
				f1[i]=0;
			}
			else if(p1==p2)
			{
				if(p2==p3) f1[i]=0;
				else
				{
					if(p3>=l[i]) f1[i]=f2[l[i]]+l[i]-p1;
					else
					{
						f1[i]=f2[l[i]]+p3-p2;
					}
				}
			}
			else if(p2>=l[i])
			{
				f1[i]=f1[l[i]];
			}
			else
			{
				if(p2==p3)
				{
					if(p2-p1==1) f1[i]=f3[p2];
					else f1[i]=f1[l[i]];
				}
				else if(p3>=l[i])
				{
					if(p2-p1==1) f1[i]=f3[p2]+l[i]-p2;
					else f1[i]=f1[l[i]]+l[i]-p2;
				}
				else
				{
					if(p2-p1==1) f1[i]=f3[p2]+p3-p2;
					else f1[i]=f1[l[i]]+p3-p2;
				}
			}
		}
		
		if(i-l[i]+1==1)
		{
			f2[i]=0;
		}
		else if(i-l[i]+1==2)
		{
			f2[i]=f2[i-1]+i-1-l[i-1];
		}
		else
		{
			int p1=l[i],p2=p1+1;
			p1=l[p1],p2=l[p2];
			if(p1==p2) f2[i]=0;
			else if(p2>=l[i]) f2[i]=f2[l[i]]+l[i]-p1;
			else f2[i]=f2[l[i]]+p2-p1;
		}
		
		if(i-l[i]+1==1) f3[i]=0;
		else
		{
			int p1=l[i-1],p2=l[i];
			if(p1==p2) f3[i]=0;
			else if(p2>=i-1) f3[i]=f1[i-1];
			else if(p1==p2-1) f3[i]=f3[p2];
			else f3[i]=f1[i-1];
		}
		ans+=f1[i];
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int op,t;
	cin>>op>>t;
	for(int p=1;p<=t;p++)
	{
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=0;
		chg(n,d);
		cout<<ans<<'\n';
	}
	return 0;
}
