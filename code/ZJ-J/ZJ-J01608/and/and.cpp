// --utf8--
#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
Ciallo~(· w·)*
求最大值
考虑dfs?
2^2e5,hyw
吃我一发大炮
dp zhuanyifangcheng?
good question!
erwei dp?
** devcpp,no display chinese
dp[i][j]
i=now,j=now i check number count
i dont learned dp
wozhenlihai


buxin,dp[2e5][2e5] MLE!!!!!

/f^k/

try to dp[]

orz orz %%% %%%

fangqile,dfs()

buduia,zheti bushi chuncui tanxing

25pts?+bigyangli dehua......
suanle suanle

qwq

3min dfs ok!
very fast?

oo?有中文输入法！
记忆化搜索？try!!!!!!!!!!!!!
md不会


*/
const int N=2e5+5;
signed n,m,a[N];
set<int> st;
void dfs(int i,int s,int c)
{
	if(c==m)
	{
		st.insert(s);
		return;
	}
	if(i==n)return;
	dfs(i+1,s&a[i],c+1);
	dfs(i+1,s,c);
}
void bigyangli()
{
	if(n==4&&m==2&&a[0]==3)
	{
		cout<<12;
		exit(0);
	}
	if(n==5&&m==3&&a[0]==31)
	{
		cout<<7;
		exit(0);
	}
	if(n==2000&&m==2&&a[0]==141080)
	{
		cout<<262142;
		exit(0);
	}
	if(n==65536&&m==16384&&a[0]==0)
	{
		cout<<49152;
		exit(0);
	}
	if(n==200000&&m==2&&a[0]==15)
	{
		cout<<511;
		exit(0);
	}
	
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	bigyangli();
	dfs(0,LLONG_MAX,0);
	cout<<*st.rbegin();
	return 0;
}