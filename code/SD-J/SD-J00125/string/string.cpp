#include<bits/stdc++.h>
#define int long long
#define N 200100
using namespace std;
inline int read(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}return x*f;}
void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');}

char c[N],nc[N];
int a[N],na[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=read();
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		sum+=a[i];
		cin>>c[i];
	}
	int mid=(sum&1)?(sum+1)/2:sum/2;
	int tot=0,dqi;
	int ll,rr;
	for(int i=1,nowsum=0;i<=n;i++)
	{
		if(nowsum+a[i]<mid)
		{
			nowsum+=a[i];
			na[++tot]=a[i];
			nc[tot]=c[i];
		}
		else if(nowsum+a[i]==mid)
		{
			if(sum&1)
			{
				if(a[i]-1)
				{
					na[++tot]=a[i]-1;
					nc[tot]=c[i];
				}
				ll=tot,rr=tot+2;
				na[++tot]=1;
				nc[tot]=c[i];
			}
			else
			{
				na[++tot]=a[i];
				nc[tot]=c[i];
				ll=tot,rr=tot+1;
			}
			dqi=i;
			break;
		}
		else if(nowsum+a[i]>mid)
		{
			if(sum&1)
			{
				if(mid-1-nowsum)
				{
					na[++tot]=mid-nowsum-1;
					nc[tot]=c[i];
				}
				na[++tot]=1;
				nc[tot]=c[i];
				ll=tot-1,rr=tot+1;
				if(a[i]+nowsum-mid)
				{
					na[++tot]=a[i]+nowsum-mid;
					nc[tot]=c[i];
				}
			}
			else
			{
				na[++tot]=mid-nowsum;
				nc[tot]=c[i];
				ll=tot,rr=tot+1;
				na[++tot]=a[i]+nowsum-mid;
				nc[tot]=c[i];
			}
			dqi=i;
			break;
		}
	}
	for(int i=dqi+1;i<=n;i++)
	{
		na[++tot]=a[i];
		nc[tot]=c[i];
	}
	int ans=0;
	while(ll!=0||rr!=tot+1)
	{
		int num=min(na[ll],na[rr]);
		na[ll]-=num;
		na[rr]-=num;
		if(nc[ll]!=nc[rr])ans+=num;
		if(na[ll]==0 && ll!=0)ll--;
		if(na[rr]==0 && rr!=tot+1)rr++;
	}
	cout<<ans;
	return 0;
}

