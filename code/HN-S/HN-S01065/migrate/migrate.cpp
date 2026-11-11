#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[200010],dp[200010][2],rr[200010],flag[200010],flag2[200010],ans;
int dfs(int j)
{
	if(flag[j]) return 0;
	flag[j]=1;
	if(j==n) return 1;
	return dfs(rr[j])+1;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ans=0;  
		cin>>n>>d;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i];
			dp[i][0]=0;
			dp[i][1]=0;
			flag2[i]=0;
		}
		dp[n][0]=1;
		dp[n][1]=0;	
		for(int i=1;i<=n;i++)
		{
			int l=i,r=n;
			while(l<r)
			{
				int mid=(l+r+1)/2;
				if(a[mid]<=a[i]+d) l=mid;
				else r=mid-1;
			}
			rr[i]=l;
		}
		for(int i=n-1;i>=1;i--)
		{
			if(rr[i]==i)
			{
				dp[i][0]=1;
				dp[i][1]=0;
			}
			else
			{
				dp[i][0]=dp[rr[i]][0]+1;
				dp[i][1]=dp[rr[i]][1];
				if(rr[i]-2>=i) 
				{
					for(int j=rr[rr[i]-2]+1;j<=rr[rr[i]-1];j++) dp[i][1]+=dfs(j);
					for(int j=rr[rr[i]-2]+1;j<=n;j++) flag[j]=0;
				}
			}
			ans+=dp[i][1];
		}
		cout<<ans<<"\n";
	}
} 
/*
小R 小P RP++

RRRRRRR    PPPPPPP            +                   +
R      R   P      P           +                   + 
R      R   P      P           +                   +
RRRRRRR    PPPPPPP            +                   +
R R        P           +++++++++++++++     +++++++++++++++
R  R       P                  +                   +
R   R      P                  +                   +
R    R     P                  +                   +
R     R    P                  +                   +

dp? dp[i][0]表示以i为开头的单径数量，dp[i][1]表示以i为开头的双径数量 
i               r[i]
单径=(唯一)单径+单径
i      r[r[i]-2]+1,r[r[i]-1]                         r[i]
双径=(不唯一)双径+单径，(唯一)单径+双径 

初始化 dp[n][0]=1,dp[n][1]=0 

我原来能做出第三题......吗？  不行，有重复  为什么会有遗漏？ 哦我把dp[i][0]当1了，看我改一改

只有重复了..............*** *飞了  算了算了40pts也行  算了算了40pts也行
*/ 
