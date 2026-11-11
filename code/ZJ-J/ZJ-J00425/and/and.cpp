#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int n,m,a[200005],id[32][200005],tt[32],maxcnt,flag,ans=0x7fffffff,col,tong[200005],tong2[200005],flag1;
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		int cnt=0;
		while(x>0)
		{
			if(x%2==1)
			{
				id[cnt][++tt[cnt]]=i;
			}
			cnt++;
			x/=2;
		}
		maxcnt=max(cnt,maxcnt);
	}
	//cout<<maxcnt<<" ";
	/*for(int i=maxcnt;i>=0;i--)
	{
		cout<<tt[i];
	}*/
	for(int i=maxcnt;i>=0;i--)
	{
		if(tt[i]<m)
		{
			continue;
		}
		else if(tt[i]==m&&!col)
		{
			flag=i;
			break;
		}
		else
		{
			if(!col)
			{
				col=1;
				for(int j=1;j<=tt[i];j++)
				{
					tong[id[i][j]]=1;
				}
			}
			else
			{
				int cnt=0;
				for(int j=1;j<=tt[i];j++)
				{
					if(tong[id[i][j]]==1)
					{
						tong2[id[i][j]]=1;
						cnt++;
					}
				}
				if(cnt==m)
				{
					for(int i=1;i<=n;i++)
					{
						tong[i]=tong2[i];
					}
					flag1=cnt;
					break;
				}
				if(cnt>m)
				{
					for(int i=1;i<=n;i++)
					{
						tong[i]=tong2[i];
					}
				}
			}
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		cout<<tong[i]<<" ";
	}
	cout<<(ans&15)<<" ";*/
	//cout<<flag1;
	if(flag>0)
	{
		//cout<<1;
		for(int i=1;i<=m;i++)
		{
			ans&=a[id[flag][i]];
			//cout<<id[flag][i]<<" ";
		}
	}
	else if(flag1>0)
	{
		//cout<<1;
		for(int i=1;i<=n;i++)
		{
			if(tong[i]==1)
			{
				ans&=a[i];
			}
		}
	}
	else
	{
		//cout<<1;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			//cout<<tong[i]<<" ";
			if(tong[i]==1&&cnt<m)
			{
				cnt++;
				ans&=a[i];
				//cout<<a[i]<<" ";
			}
		}
	}
	cout<<ans;
 	return 0;
}
/*5 3
31 3 1 15 7
*/