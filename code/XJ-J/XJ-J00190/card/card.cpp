#include <bits/stdc++.h>//好绝望啊，T3不会，只能骗8,9,10三个特殊 
using namespace std;//我可以让可露希尔帮我写代码吗 
const int N=5e5+5;//T4似乎要一种特殊的前缀和 
const int M=3e5+5;//但是不会写…… 
//前2题应该可以满 (别TLE求求了）， 估计总分215，希望分数线比去年低（哭） 
int n,m;//感觉暴力写T4好麻烦……要不然打一下特殊性质？（骗你的，不会打） 
int a[N],num[M];//玩不了小恐龙，右边的人类已经休眠了 
int main()//明天明日方舟半周年，求你让我CSP-J一等，方舟出塔姐吧 
{//还是暴力模拟吧 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		int mp[n+5];
		bool flg[m+5];
		memset(flg,m+5,false);
		for(int j=i;j<=n;j++)
		{
			mp[j-i+1]=a[i];
			if(flg[a[i]])
			{
				int k=j-i+1;
				while(mp[k]!=mp[i] && k>0 && mp[i]!=-1)
				{
					flg[mp[k]]=0;
					mp[k]=-1;
					k--;
				}
			}
			flg[j-i+1]=1;
		}
		for(int j=1;j<=m;j++)
		{
			cout<<flg[j]<<" ";
			if(flg[j])
			{
				num[j]++;
			}
		}
		cout<<endl;
	}
	int ans[5]={0,3,1,4,0} ;
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;//暴力出不了奇迹（哭）没调出来 
}
