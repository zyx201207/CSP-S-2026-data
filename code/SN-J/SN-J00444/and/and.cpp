#include<bits/stdc++.h>
using namespace std;
int a[200005],b[100];
bool vis[200005];
int n,m,ans;
void put(int x)
{
	int cnt=0;
	while(x)
	{
		if(x%2==1) b[cnt]++,cnt++;
		else cnt++;
		x/=2; 
	}
}
bool check(int x,int y)
{
	int cnt=0;
	while(x)
	{
		if(cnt==y)
		{
			return x%2==1;
		} 
		x/=2;
		cnt++;
	}
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),put(a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=29;i>=1;i--)
	{
		if(b[i]>=m)
		{
		    for(int j=1;j<=n;j++)
			{
				if(vis[j]) continue;
				if(!check(a[j],i)) vis[j]=1;
			}
			bool flag=0;
			int cnt=0;
			for(int j=1;j<=n;j++)
			{
				if(cnt==m) break;
				if(!vis[j])
				{
					if(flag==0) ans=a[j],flag=1;
					ans&=a[j];
					cnt++;
				} 
			} 
			break;
		}
	}
	printf("%d",ans);
	return 0;
}
