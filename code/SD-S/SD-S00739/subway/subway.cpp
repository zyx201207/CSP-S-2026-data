#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct s
{
	int number;//每条地铁对应的站点 
	int time;//每条地铁在对应站点的时间 
};
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,m,n, d,q;
	cin>>c>>n>>m>>d>>q;
	int t;
	int mi=100000;//工具  
	int dp[n][m]={};//不要误会我要用DP，我只是用动态规划思想做题而已
	//所以为了最基本的尊重，用一个DP数组来记录 
	int a[m]={},b[n][m]={};//a是站厅到地铁站的时间
	//b是整个地铁系统的不同路线的时间汇总 
	for(int i=0;i<m;i++)
	{
		cin>>a[i];	
	}	
	for(int i=0;i<n;i++)
	{
		cin>>t;
		s c[t];//工具数组，我不准备用它，对不起 
		for(int j=0;j<t;j++)
		{
			cin>>c[j].number >>c[j].time ;
			b[i][c[j].number -1]=c[j].time; 
		}
	}//目前一切良好
	int start=0;
	int end=0;
	//显而易见是起始和终止的站台 
	int alltime=0;//全部时间 
	int f=0;
	int M7=0;
	for(int i=0;i<q;i++)
	{
		f=0;
		alltime=0;//初始化 
		cin>>start>>end;
		alltime+=a[start-1]+a[end-1];
		for(int j=0;j<n;j++)
		{
			if(b[j][start-1]!=0&&b[j][end-1]!=0)
			{
				alltime+=b[j][start-1]+b[j][end-1];
				cout<<alltime;
				break;
				f=1;
			}		
		}
		for(int j=0;j<n;j++)
		{
			if(b[j][start-1]!=0)
			{
				dp[j][start-1]=b[j][start-1];
				M7=j;
				break;
			}
		}// 666不是我键盘出问题了，只能用中文输入了，我超威！ 
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<m;k++)
			{
				if(b[j][k]==0)
				{
					dp[j][k]=-1;
				}
			}
		}//打标记 
		for(int j=0;j<n;j++)
		{ 
			for(int k=0;k<m;k++)
			{
				mi=1000000; 
				for(int M14=0;M14<m;M14++)
				{
					if(mi>dp[j][M14])
					{
						mi=min(mi,dp[j][M14]);
					}
				}
				if(dp[j][k]==0&&dp[M7][start-1])
				{
					dp[j][k]=min(mi,dp[j-1][k])+b[j][k];
					//好吧我认了，我用的就是DP，我把状态转移方程都写出来了，但是我确实不会这道题来着... 
				}
			}
		}//我现在就像那个活字印刷术，我真的打什么代码都得去复制前面的，太痛苦了 
		mi=1000000;
		for(int j=0;j<n;j++)
		{
			if(mi>dp[end-1][j]&&dp[end-1][j]!=0)
			{
				mi=min(mi,dp[end-1][j]);
			}
		}
		alltime+=mi;
		cout<<alltime;
		//把这坨石山弄完算了，运行不起来也没关系，我现在这个条件也修不了ｂｕｇ了
		//对的我现在一打英文就是这样
		//Ｗｈａｔ　ｃａｎ　Ｉ　ｓａｙ？
		//复制一下我的代码对比一下 ：alltime　ａｌｌｔｉｍｅ 
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
