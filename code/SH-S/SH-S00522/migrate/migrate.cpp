#include<bits/stdc++.h>
using namespace std;
struct node
{
	int step,cnt;
}ans[5005][5005];
int a[5005];
int n ,d;
void dfs(int past,int now,int step)
{
	if(now > n) return;
	if(step!=0)
	{
		if(ans[past][now].step >step)
		{
			ans[past][now].step = step;
			ans[past][now].cnt = 1;
		}
		else if(ans[past][now].step == step)
		{
			ans[past][now].cnt++;
		}
	}
	for(int i = now+1; i <= n; i++)
	{
		if(now+d>=a[i])
		{
			dfs(past,a[i],step+1);	
		} 
	}
} 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin >> c;
	int t;
	cin >> t;
	while(t--)
	{
		memset(ans,0x3f,sizeof(ans));
		int cnt = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++)
		{
			
			dfs(i,i,0);
			for(int j = i+1; j <= n; j++)
			{
				if(ans[i][j].cnt == 2)cnt++;
			}
		}
		
		
		cout << cnt<<"\n";
	}
	
	
	return 0;
}
