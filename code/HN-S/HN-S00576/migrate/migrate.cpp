#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,d,a[N],cnt[N],l[N],s[N],r[N],dp[N],sum,f[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cnt[i]=l[i]=r[i]=dp[i]=f[i]=0;
		sum=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int L=1;
		for(int i=1;i<=n;i++)
		{
			while(a[i]-a[L]>d)L++;
			l[i]=L;
		}
		int R=n;
		for(int i=n;i>=1;i--)
		{
			while(a[R]-a[i]>d)R--;
			r[i]=R;
		}
		for(int i=1;i<=n;i++)
		{
			f[i]++;
			if(r[i]>i){
				if(r[i]!=r[i-1]){
					f[r[i]]+=f[i];
				}
			}
		}
		for(int i=n;i>=1;i--)
		{
			dp[i]++;
			if(l[i]<i)
			{
				if(l[i]!=l[i+1])
					dp[l[i]]+=dp[i];
			}
			s[i]=s[i+1]+dp[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(r[i]>i+1)
			{
				if(r[r[i]]==r[i])continue;
				if(r[i]==i+2){
					sum+=(s[r[i+1]]-s[i+2])*f[i];
				}
				else{
					if(r[r[i]]==r[r[i]-1]&&r[r[i]-1]!=r[r[i]-2])
						sum+=(s[r[r[i]]]-s[r[r[i]-2]])*f[i];
				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
/*
0 1
8 3
0 1 2 4 8 10 11 13
*/
