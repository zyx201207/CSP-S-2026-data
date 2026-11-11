#include<bits/stdc++.h>
using namespace std;
int a[500005];
map<char,int> ma[500005];
struct st{
	int l,r;
};st f[500005];
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,i,j,minn=2147483640,x,sum=0,cnt=0,maxx=-9999999,k=2147483640,flag=0;
	cin>>n>>m;
	cin>>a[1]>>a[2];
	k=a[2]-a[1];
	for(i=3;i<=n;i++)
	{
		cin>>a[i];
		if(k!=a[i]-a[i-1])
		{
			flag=1;
		}
	}
	if(flag==1)
	{
		sort(a+1,a+n+1); 
		while(m>0)
		{
			memset(f,0,sizeof(f));
			for(i=2;i<=n-1;i++)
			{
				if((a[i]-a[i-1]==0)&&(a[i+1]-a[i]==0))
				{
					continue;
				} 
				f[i].l=a[i]-a[i-1];
				f[i].r=a[i+1]-a[i];
			}
			
			minn=2147483640;
			x=0;
			for(i=2;i<=n-1;i++)
			{
				if(minn>(f[i].l+f[i].r) && (f[i].l+f[i].r!=0))
				{
					
					minn=f[i].l+f[i].r;
					x=i;
				}
			}
		
			if(m>=minn)
			{
				a[x-1]+=f[x].l;
				a[x]+=f[x].r;
				m-=minn;
			}
			else
			{
				break;
			}
			cnt=1;
			for(i=1;i<=n;i++)
			{
				cnt=i;
				sum=1;
				while(a[++i]==a[cnt])
				{		
					sum++;
				}
				maxx=max(maxx,sum);
			}
		}
		cout<<maxx;		
	}
	else
	{
		int t=m;
		if(k==1)
		{
			sum=1;
			for(i=1;i<=m;i++)
			{
				if(t-i>=0)
				{
					sum++;
					t-=i;
				}
				else
				{
					break;
				}
			}
			
			cout<<sum;
		}
		else
		{
			for(i=1;i<=m;i+=k)
			{
				if(t-i>=0)
				{
					sum++;
					t-=i;
				}
				else
				{
					break;
				}
			}
			cout<<sum;
		}
	}
	return 0;
}
