#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int N=2e6+9,inf=1e9;
int n,d,x[N],r[N],dp[N][6];
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	int j=1;
	for(int i=1;i<=n;i++)
	{
		while(j<=n && x[j]-x[i]<=d)
			j++;
		r[i]=j-1;
//		cout<<r[i]<<" ";
	}
//	cout<<r[1]<<"!"<<endl;
	for(int i=n;i>=1;i--){
		dp[i][0]=dp[i][1]=0;
		dp[i][3]=dp[i][2]=0;
		dp[i][4]=0;dp[i][5]=0;
	}
	for(int i=n;i>=1;i--)
	{
		if(r[i]==i)/*一种*/
			dp[i][0]=0;
		else if(r[i]==i+1)
			dp[i][0]=dp[r[i]][0];
		else if(r[i]==i+2)
			dp[i][0]=dp[r[i]][4];
		else
			dp[i][0]=dp[r[i]][1];
		
		
		if(i>=3)
		{
			int l=max(i+1,r[i-2]+1),rr=r[i-1];
			if(r[i]==i)
			{
				dp[i][1]=0;
			}
			else if(r[i]==i+1)
			{
				if(r[i-1]==i+1)
				{
					if(r[i-2]<=i)
					dp[i][1]=dp[r[i]][2];
					else
						dp[i][1]=0;
				}
				else
				{
					dp[i][1]=dp[r[i]][0];
				}
			}
			else if(r[i]==i+2)
			{
				if(r[i-1]==i+2)
				{
					if(r[i-2]==i+2)
						dp[i][1]=0;
					else if(r[i-2]==i+1)
						dp[i][1]=dp[r[i]][2];
					else if(r[i-2]<=i)
						dp[i][1]=dp[r[i]][3];
				}
				else if(r[i-1]==i+1)
				{
					dp[i][1]+=(rr-l+1)+dp[r[i]][5];
				}
				else
				{
					dp[i][1]+=dp[r[i]][4];
				}
			}
			else
			{
				if(rr<=i)
				{
					dp[i][1]=dp[r[i]][1];
				}
				else
				{
					if(rr==r[i]-1)
					dp[i][1]=(rr-l+1)+dp[r[i]][5];
					else if(rr==r[i])
					{
						if(r[i-2]==r[i]-1)
						dp[i][1]=dp[r[i]][2];
						else if(r[i-2]==r[i])
							dp[i][1]=0;
						else
							dp[i][1]=(rr-l)+dp[r[i]][3];
					}
					else if(rr==r[i]-2)
					{
						dp[i][1]=(rr-l+1)+dp[r[i]][1];
					}
					else
						dp[i][1]=(rr-l+1)+dp[r[i]][1];
				}
			}
		}
		if(r[i]==i)
			dp[i][2]=1;
		else if(r[i]==i+1)
			dp[i][2]=1+dp[r[i]][2];
		else
			dp[i][2]=(r[i]-i)+dp[r[i]][3];
		if(i>=2)
		{
			int l=max(i+1,r[i-1]+1),rr=r[i];
			if(r[i]==i)
			{
				dp[i][3]=1;
			}
			else if(r[i]==i+1)
			{
				if(r[i-1]==r[i])
					dp[i][3]=1;
				else
					dp[i][3]=1+dp[r[i]][2];
			}
			else
			{
				if(r[i-1]==rr)
					dp[i][3]=1;
				else if(r[i-1]==rr-1)
					dp[i][3]=1+dp[r[i]][2];
				else dp[i][3]=(rr-l+1)+dp[r[i]][3];
			}
		}
		if(i>=2)
		{
			int rr=r[i-1];
			if(r[i]==i)
			{
				dp[i][4]=0;
			}
			else if(r[i]==i+1)
			{
				if(r[i-1]==i+1)
				{
					dp[i][4]=dp[r[i]][2];
				}
				else
				{
					dp[i][4]=dp[r[i]][0];
				}
			}
			else if(r[i]==i+2)
			{
				if(r[i-1]==i+2)
				{
					dp[i][4]=dp[r[i]][3]+1;
				}
				else if(r[i-1]==i+1)
				{
					dp[i][4]=dp[r[i]][5]+1;
				}
				else 
				{
					dp[i][4]=dp[r[i]][4];
				}
			}
			else
			{
				if(r[i-1]<=i)
				{
					dp[i][4]=dp[r[i]][1];
				}
				else
				{
					int l=i+1;
					if(rr==r[i])
					{
						dp[i][4]=(rr-l)+dp[r[i]][3];
					}
					else if(rr==r[i]-1)
					{
						dp[i][4]=(rr-l+1)+dp[r[i]][5];
					}
					else if(rr==r[i]-2)
					{
						dp[i][4]=(rr-l+1)+dp[r[i]][1];
					}
					else
						dp[i][4]=(rr-l+1)+dp[r[i]][1];
				}
			}
		}
		if(i>=2)
		{
			int rr=r[i-1];
			if(r[i]==i)
			{
				dp[i][5]=0;
			}
			else if(r[i]==i+1)
			{
				if(r[i-1]==i+1)
				{
					dp[i][5]=0;
				}
				else
				{
					dp[i][5]=dp[r[i]][0];
				}
			}
			else if(r[i]==i+2)
			{
				if(r[i-1]==i+2)
				{
					dp[i][5]=0;
				}
				else if(r[i-1]==i+1)
				{
					dp[i][5]=dp[r[i]][5];
				}
				else 
				{
					dp[i][5]=dp[r[i]][4];
				}
			}
			else
			{
				if(r[i-1]<=i)
				{
					dp[i][5]=dp[r[i]][1];
				}
				else
				{
					int l=i+1;
					if(rr==r[i])
					{
						dp[i][5]=0;
					}
					else if(rr==r[i]-1)
					{
						dp[i][5]=dp[r[i]][5];
					}
					else if(rr==r[i]-2)
					{
						dp[i][5]=dp[r[i]][1];
					}
					else
						dp[i][5]=dp[r[i]][1];
				}
			}
		}
//		cout<<dp[i][0]<<"!";
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=dp[i][0];
	}
	cout<<ans<<endl;
}
/*
考虑怎么刻画这个条件
首先两两之间的长度是尽力跳
两条路径，那么就是尽力跳中，存在一个节点的前一个节点可以放水跳到下一个节点
从后往前进行dp
先找到最远的到达距离
然后是dp[i][2]
设为i号节点的路径数为1 i-1 为空
i,i-1 的路径数为1
还有最后时候是2路径也要分讨论

i 路径为2且i-1 为空
这里就是说

i 路径为2且 i-1 不为空

少分讨论了一种

i 和 i-1 为 1，但是 i-2 为空

还需要i 为 1，且i-1 为>=2
*/
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T=1;
	cin>>c>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}