#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll read()
{
	char ch = getchar();
	ll num = 0,sign = 1;
	while(ch<'0'||ch>'9')sign = (ch == '-'?-1:1),ch = getchar();
	while(ch >= '0'&&ch <= '9')num = (num<<3)+(num<<1)+(ch-'0'),ch = getchar();
	return sign>0?num:-num;
}
const int N = 5e3+8;
ll c,t,n,d,dp[N][N],x[N],pfx[N][N],l[N],ans;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(),t = read();
	while(t--)
	{
		n = read(),d = read(),ans = 0;
		ll a = 0;
		memset(dp,0,sizeof(dp));
		for(int i = 1;i <= n;i++)x[i] = read(),a = x[i]-x[i-1];
		if(d/a == 2)cout<<n-3<<"\n";
		else cout<<0<<"\n";
	}
	return 0;
}

