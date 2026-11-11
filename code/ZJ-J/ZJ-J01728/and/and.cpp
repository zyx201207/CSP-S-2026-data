#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s[200100][33],a[200100],ans[200100],vis[200100],cnt[32],ans1;

bool cmp(int x,int y)
{
	return x>y;
}

void dfs(int x,int cnt)
{
	if(cnt==m)
	{
		int sum=ans[1];
		for(int i=2;i<=m;i++)
		{
			sum&=ans[i];
		}
		ans1=max(ans1,sum);
		return;
	}
	else if(x>n) return;
	
	ans[cnt+1]=a[x];
	dfs(x+1,cnt+1);
	
	dfs(x+1,cnt);
}

void work(int num)
{
	int x=a[num],i=0;
	while(x)
	{
		s[num][i]=x%2;
		x=x>>1;
		if(s[num][i]) cnt[i]++;
	}
//	for(int i=5;i>=0;i--) cout<<s[num][i];
//	cout<<endl;
}
void work2()
{
	int ans1=ans[1];
	for(int i=2;i<=m;i++)
	{
		ans1&=ans[i];
	}
	cout<<ans1;
}
signed main(void)
{
	freopen("and.in","r",stdin);
	freopen("and.ont","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=30)
	{
		dfs(1,0);
		cout<<ans1;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++) work(i);
    for(int i=31;i>=0;i--)
    {
    	int cnt=0;
    	for(int j=1;j<=n;j++)
    	{
    		if(s[j][i]==1)
    		{
    			cnt++;
    			ans[cnt]=a[j];
    			if(cnt==m)
    			{
    				work2();
    				return 0;
				}
			}
		}
	}
}