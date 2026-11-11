#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],maxn,ans,last;
vector<int> dp[33];
bool f[33][N],panduan[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1,k,cnt;i<=n;i++)
	{
		cin>>a[i];
		k=a[i];cnt=0;
		while(k)
		{
			if(k&1){dp[cnt].push_back(i);f[cnt][i]=1;}
			k>>=1;cnt++;
		}maxn=max(maxn,cnt);
	}
	for(int i=1;i<=n;i++)panduan[i]=1;
	for(int i=maxn;i>=0;i--)
	{
		if(dp[i].size()<m)continue;
		for(int j=i,sum=0;j>=0;j--)
		{
			sum=0;
			ans=0;
			for(int k=1;k<=n;k++)
			{panduan[k]&=f[j][k];
				if(panduan[k])
				{
					if(ans==0)ans=a[k];
					else ans&=a[k];sum++;
				}
			}
			if(sum==m)
			{
				cout<<ans;
				return 0;
			}
			if(sum<m)
			{
				cout<<last;
				return 0;
			}
			last=ans;
		}
	}
	cout<<0;
	return 0;
}
