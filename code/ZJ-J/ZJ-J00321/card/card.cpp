#include<bits/stdc++.h>
using namespace std;
//RP++
//Let me AK CSP-J pls CCF!!!
//play egg!I cant do T4!!!
//I cant AK CSP-J!!!
//张锦峰老师，我还记得你!
//免责申明:此处人名为cxslzx的上一届毕业生
int read()
{
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}
int n,m,i,a[500005],cnt[200005],j,k;
bool A=1;
int sum[200005];
void solve_specialA()
{//now a1<=a2<=...<=an
//use a cha fen to solve it
	int cnt=0;
	for(i=n;i>=1;i--)
	{
		if(a[i]==a[i+1])cnt++;
		else cnt=1;
		sum[a[i]]++;
	}
	sum[0]=0;
	for(i=1;i<=m;i++)
		sum[i]+=sum[i-1],cout<<sum[i]<<' ';
}
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
//骗到你了吗，我要上人类迷惑行为大赏 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();m=read();
	for(i=1;i<=n;i++)
		a[i]=read(),A&=(a[i-1]<=a[i]);
	if(A)return solve_specialA(),0;
	for(i=1;i<=n;i++)
	{//枚举每一轮游戏
		int last[5005]={0};
		int stack[5005]={0},top=0;
		for(j=i;j<=n;j++)
		{
			if(last[a[j]]>top)last[a[j]]=0;
			if(!last[a[j]])stack[++top]=a[j],last[a[j]]=top;
			else top=last[a[j]];
		}
		for(j=1;j<=top;j++)
			cnt[stack[j]]++;
	}
	for(i=1;i<=m;i++)
		cout<<cnt[i]<<' ';
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
10:07 I finish the special points A,+4pts
10:07 it is 52 pts
10:16 I think I find the AC way!
10:18 I think it is wrong 
10:30 I want to play game for a while
写点思路吧
10:36 I go to the WC
10:48 我放弃了这道题，所以说我和AK CSP-J无缘
距离CSP-J还有-2.5个小时，你居然还在颓废！
11:05 完成4道题的整活,开始玩小恐龙
11:10 小恐龙2906分，被翼龙肘击 
11:18 莫名其妙的想到了怎么做，但是不会
11:32 国际象棋赢了  GG
*/
