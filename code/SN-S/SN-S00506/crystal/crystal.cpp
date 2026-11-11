//西安含光中学 吕家名 SN-S00506 
/*
5:16成功重塑代码 如此美妙 
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[600010];
struct fdf
{
	long long cost,len,u;//以i结尾的最长连续串 
	//cost花费
	//len长度
	//u抹平的能量值 
}dp[600010],dp2[600010];
int main()
{
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[1].cost=0;//花费为0 长度为1 
	dp[1].len=1;
	//dp[1].u=a[1];可以先不要这个东东 
	for(long long i=2;i<=n;i++)
	{
		//扬升资格与花费：len*(a[i]-a[i-1]) 可以让它继续延续 
		//sub4爆炸 炸在i=313324   245826
		if(dp[i-1].cost+1LL*dp[i-1].len*(a[i]-a[i-1])<=m)
		{
			dp[i].cost=dp[i-1].cost+1LL*dp[i-1].len*(a[i]-a[i-1]);//整体的花费
			dp[i].len=dp[i-1].len+1LL; 
		}
		else
		{
			dp[i].cost=0;
			dp[i].len=1;
		}
	}
	long long ans=1;
	for(int i=1;i<=n;i++)
	{
		//cout<<a[i]<<" "<<dp[i].cost<<" "<<dp[i].len<<" "<<i<<endl;
		ans=max(ans,dp[i].len);
	}
	cout<<ans;
	test3 
}*/
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[600010];
struct fdf
{
	long long cost,len,u;//以i结尾的最长连续串 
	//cost花费
	//len长度
	//u抹平的能量值 
}dp[600010],dp2[600010];
priority_queue<int,vector<int>,greater<int> > q;//我们尽可能把它压进去 如果遇到扬升不动的就撇了最小的一部分收回花费 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=1;
	long long cost=0,u=a[1],len=1;//现在值保持在u 花费了cost 长度为x 
	q.push(a[1]);//弹出来的要是最小值 
	for(int i=2;i<=n;i++) 
	{
		int costi=a[i]-u;
		if(cost+costi*len<=m)
		{
			q.push(a[i]);//进去
			u=a[i];
			cost=cost+costi*len;
			len++;
			ans=max(ans,len);
		}
		else//不行的话 
		{
			//无法扬升 
			int ke=0;
			while(1)
			{
				if(q.empty())
				{
					break;//弹出所有仍然不能扬升 
				}
				if(cost+costi*len<=m)//终于可以了 
				{
					ke=1;
					break; 
				}
				int kr=q.top();
				len--;
				q.pop();
				cost-=(u-kr);//白培养了 收回这一部分 
				ans=max(ans,len);
			}
			if(ke)
			{
				q.push(a[i]);//进去
				u=a[i];
				cost=cost+costi*len;
				len++;
				ans=max(ans,len);
			}
			else
			{
				while(!q.empty()) 
					q.pop();
				q.push(a[i]);
				cost=0;
				u=a[i];
				len=1;
				ans=max(ans,len);
			} 	
		} 
	}
	cout<<ans; 
	 
}
