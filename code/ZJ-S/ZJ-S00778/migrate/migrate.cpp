#include<bits/stdc++.h>
using namespace std;const int op=2e6+10;long long n,d;
int x[op];long long m=0;int ans,ans1;
void dfs(int i,int j,int now)
{
	if(i==j)
	{
		ans=min(ans,now);
	}
	else
	{
		for(int k=1+i;k<=j;k++)
		{
			if(x[k]-x[i]<=d)
			{
				dfs(k,j,now+1);
			}
			else break;
		}
	}
}//ans is right!
void dfs1(int i,int j,int howmany)
{
	if(i==j && howmany==ans)ans1++;
	else
	{
		for(int k=1+i;k<=j;k++)
		{
			if(x[k]-x[i]<=d && howmany<=ans)
			{
				dfs1(k,j,howmany+1);
			}
			else break;
		}
	}
}
int main()
{
	/*我是山间一缕风，也能燃起一团火
	我是地上一朵小花，也有春天的颜色
	小小的我，小小的我，全部的爱献给祖国
	小小的我，小小的我，谱写一首爱之歌*/
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		long long realans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=2e9;ans1=0;
				dfs(i,j,0);
				dfs1(i,j,0);
				//cout<<i<<" "<<j<<":"<<ans1<<endl;
				if(ans1==2)
				{
					realans++;
				}
			}
		}
		cout<<realans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
