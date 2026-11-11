#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int n,C,t,d;
int x[N],num[N],cnt[N];
bool bfs(int u,int y)
{
	memset(num,0x3f,sizeof(num));
	memset(cnt,0,sizeof(cnt));
	queue<int>q;
	q.push(u);
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		if(top==y)
			continue;
		if(top>y)
			continue;
		int max=x[top]+d;
		for(int i=top+1;i<=n;i++)
		{
			int sum=0;
			if(x[i]<=max)
			{
				sum+=num[top];
				sum++;
				if(sum<num[i])
				{
					cnt[i]=1;
					num[i]=sum;
					q.push(i);
				}
				else
				{
					cnt[i]++;
				}
				
			}
			else
				break;
		}
	}
	if(cnt[y]==2)
	{
		return true;
	}
	return false;
}
int main()
{
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>C>>t;
	int ans=0;
	while(t--)
	{
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int s=1;s<=n;s++)
		{
			for(int e=s+1;e<=n;e++)
			{
				if(bfs(s,e))
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
