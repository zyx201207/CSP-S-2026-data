#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,i,j,cnt,m,fl,sum,f[200010],g[200010],b[200010],ans,a[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	fl=0;ans=(1<<30)-1;
	for(i=30;i>=0;i--)
	{
		for(j=1;j<=cnt;j++)b[j]=0;
		cnt=0;
		for(j=1;j<=n;j++)
		{
			g[j]=0;
			if((a[j]&(1<<i))>0&&(f[j]==1||!fl))
				b[++cnt]=j;
//			else if(f[j]==1)
//				f[j]=0;
		}
		//cout<<cnt<<" ";
		if(cnt>=m)
		{
			sum=0;
			if(!fl)
			{
				for(j=1;j<=cnt;j++)
					f[b[j]]=1,sum++;
				//cout<<sum<<"\n";
				if(sum<=m)
				{
					f[b[1]]=2;
					for(j=1;j<=cnt;j++)
						ans&=a[b[j]],f[b[j]]=2;
				}
				if(sum==m)cout<<ans,exit(0);
				if(sum<m)
				{
					m-=sum;
					//for(j=1;j<=n;j++)f[j]=0;
				}
				fl=1;
			}
			else
			{
				for(j=1;j<=cnt;j++)
					g[b[j]]=1;
				for(j=1;j<=n;j++)
					if(f[j]==1&&g[j]==1)
						g[j]=1,sum++;
					else g[j]=0;
				if(sum<=m)
				{
					for(j=1;j<=n;j++)
						if(g[j]==1)
							ans&=a[j],f[b[j]]=2;
				}
				if(sum==m)cout<<ans,exit(0);
				if(sum<m)
					m-=sum;
				else
				{
					for(j=1;j<=n;j++)
						if(f[j]==1&&g[j]!=1)
							f[j]=0;
				}
				//cout<<sum<<"\n";
			}
			//cout<<ans<<"\n";
		}
	}
	//cout<<1;
	if(m)
	{
		for(i=1;i<=n;i++)
			if(f[i]==1)
			{
				ans&=a[i];
				m--;
				if(m==0)break;
			}
	}
	if(ans==(1<<30)-1)cout<<0,exit(0);
	cout<<ans;
}
