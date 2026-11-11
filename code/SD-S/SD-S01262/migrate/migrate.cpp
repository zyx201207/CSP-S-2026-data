#include<bits/stdc++.h>
#define N 20010
using namespace std;
long long T,OP;
struct node
{
	long long l,r;
};
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>OP>>T;
	if((OP>=1&&OP<=10)||(OP==19||OP==20||OP==21))
		while(T--)
		{
			node S[N];
			long long t=0;
			long long n,m;
			cin>>n>>m;
			long long a[N]={};
			for(long long i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			for(long long i=1;i<=n-3;i++)
			{
				if(a[i+3]-a[i+2]<=m&&a[i+2]-a[i]<=m&&a[i+3]-a[i+1]<=m&&a[i+1]-a[i]<=m&&a[i+3]-a[i]>m)
				{
					S[++t].l=i,S[t].r=i+3;
				}
			}
			long long cnt=0;
			if(t==1)
			{
				long long temp_l=1,temp_r=n;
				for(long long i=S[1].l-1;i>=1;i--)
				{
					if(a[i+1]-a[i]>m)
					{
						temp_l=i+1;
						break;
					}
				}
				for(long long i=S[1].r+1;i<=n;i++)
				{
					if(a[i]-a[i-1]>m)
					{
						temp_r=i-1;
						break;
					}
				}
				cnt=(S[1].l-temp_l+1)*(temp_r-S[1].r+1);
				cout<<cnt<<"\n";
				continue;
			}
			for(long long i=1;i<=t;i++)
			{
				if(i==1)
				{
					long long temp_l=1,temp_r=S[i+1].r-1;
					for(long long i=S[i].l-1;i>=1;i--)
					{
						if(a[i+1]-a[i]>m)
						{
							temp_l=i+1;
							break;
						}
					}
					for(long long i=S[i].r+1;i<S[i+1].r;i++)
					{
						if(a[i]-a[i-1]>m)
						{
							temp_r=i-1;
							break;
						}
					}
					cnt+=(S[i].l-temp_l+1)*(temp_r-S[i].r+1);
				}
				else if(i==t)
				{
					long long temp_l=S[i-1].l+1,temp_r=n;
					for(long long i=S[i].l-1;i>S[i].l;i--)
					{
						if(a[i+1]-a[i]>m)
						{
							temp_l=i+1;
							break;
						}
					}
					for(long long i=S[i].r+1;i<=n;i++)
					{
						if(a[i]-a[i-1]>m)
						{
							temp_r=i-1;
							break;
						}
					}
					cnt+=(S[i].l-temp_l+1)*(temp_r-S[i].r+1);
				}
				else
				{
					long long temp_l=S[i-1].l+1,temp_r=S[i+1].r-1;
					for(long long i=S[i].l-1;i>S[i].l;i--)
					{
						if(a[i+1]-a[i]>m)
						{
							temp_l=i+1;
							break;
						}
					}
					for(long long i=S[i].r+1;i<S[i+1].r;i++)
					{
						if(a[i]-a[i-1]>m)
						{
							temp_r=i-1;
							break;
						}
					}
					cnt+=(S[i].l-temp_l+1)*(temp_r-S[i].r+1);
				}
			}
			cout<<cnt<<'\n';
		}
	else if(OP==11||OP==12)
	{
		while(T--)
		{
			long long n,m;
			long long a[200010]={};
			cin>>n>>m;
			for(long long i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			long d=a[2]-a[1];
			if(d>m)
			{
				cout<<"0\n";
				continue;
			}
			long long x=d/m;
			long long cnt=0;
			for(long i=x+1;i<=2*x-1;i++)
			{
				cnt+=n-i;
			}
			cout<<cnt<<"\n";
		}
		
	}
	return 0;
}
