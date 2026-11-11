# include<bits/stdc++.h>
# define int long long
using namespace std;
const int MX = 2e5;
const int M = 30;
bool f[M + 10][MX + 10];
int cnt[M + 10];
int a[MX + 10];
int n,m;
int ue[M + 10],cct;
/*int solve_2000()
{
	dp[1] = a[1];
	for(int i = 2;i <= n;i++)
	{
		for(int j = m;j > 1;j--)
		{
			
			dp[j] = max(dp[j],dp[j - 1] & a[i]);
			cout << dp[j] << " " << dp[j - 1] << " " << a[i] << " " << (dp[j - 1] & a[i]) << endl;
		}
		dp[1] = max(dp[1],a[i]);
	}
	return dp[m];
}*/
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		for(int j = 0;j <= M;j++)
		{
			f[j][i] = (a[i] & (1 << j));
			//
		//	cout << f[j][i];
			//
			cnt[j]+=f[j][i];
		}
		//
//		cout << endl;
		//
	}
	int ans = 0;
	for(int i = 0;i <= M;i++)
	{
//		cout << cnt[i] << endl;
		if(cnt[i] >= m)
		{
			ue[++cct] = i;
			ans+=(1 << i);
		} 
		cnt[i] = 0;
	}
	/*
	for(int i = 1;i <= cct;i++)
	{
		cout << ue[i] << endl;
	}
	*/
	for(int i = 1;i <= n;i++)
	{
		cnt[ue[cct]]+=f[ue[cct]][i];
		for(int j = cct - 1;j >= 1;j--)
		{
			f[ue[j]][i] = f[ue[j + 1]][i] && f[ue[j]][i];
			cnt[ue[j]]+=f[ue[j]][i];
		}
	}
	int ctt = 0;
	for(int i = 1;i <= cct;i++)
	{
	//	cout << ue[i] << ":" << cnt[ue[i]] << " ";
		cnt[ue[i]]-=ctt;
		ctt+=cnt[ue[i]];
		if(ctt < m)
		{
//			cout << cct << "gg" << endl; 
			ans-=(1 << ue[i]);
		 } 
	}
/*	if(n <= 2000) 
	{
		cout << solve_2000();
		return 0;
	}*/
	cout << ans << endl;
	return 0;
}
