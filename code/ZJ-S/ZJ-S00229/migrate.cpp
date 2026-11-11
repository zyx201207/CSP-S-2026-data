#include<bits/stdc++.h>
using namespace std;
const int maxN=5e5+10;
int solution,n,ans;
int b[maxN];
long long d;
long long x[maxN];
void dfs(int now,int l,int r,int step,int aim)
{
	if(solution>2) return;
	if(step>aim) return;
	if(now>r) return;
	if(now==r)
	{
		if(step==aim) solution++;
		return ;
	}
	for(int i=now+1;i<=b[now];i++) dfs(i,l,r,step+1,aim);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		//two-point find the longest
		int r=1;
		for(int l=1;l<=n;l++)
		{
			while(x[r]-x[l]<=d&&r<=n) r++;
			b[l]=r-1;
		}
		for(int l=1;l<=n;l++)
		{
			for(int r=l+1;r<=n;r++)
			{
				//find the smallest ans
				int now=l;
				int step=0;
				int flag=0;
				while(now<r)
				{
					if(now==b[now])
					{
						flag++;
						if(flag==2) break;
					}
					now=b[now];
					step++;
				}
				solution=0;
				if(flag==1)
					dfs(l,l,now,0,step);
				else
					dfs(l,l,r,0,step);
				if(solution==2) ans++;	
			}
		}
		cout<<ans<<"\n";
		
		for(int i=1;i<=n;i++) b[i]=0;
	}
}
//greed