#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=2e5+10;
ll n,sum,a[N];
char c[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i]>>c[i],sum+=a[i];
//	if(sum<=5000)
	{
		string s="";
		ll dp[5010][5010];
		memset(dp,0,sizeof(dp));
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=a[i];j++)
				s+=c[i];
		string t=s;
		reverse(s.begin(),s.end());
		for(ll i=0;i<s.size();i++)
		{
			if(s[i]==t[0])
			{
				for(ll j=i;j<s.size();j++) dp[j][0]=1;
				break;
			}
		}
		for(ll i=0;i<t.size();i++)
		{
			if(t[i]==s[0])
			{
				for(ll j=i;j<t.size();j++) dp[0][j]=1;
				break;
			}
		}
		for(ll i=1;i<s.size();i++)
		{
			for(ll j=1;j<t.size();j++)
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				if(s[i]==t[j])
				{
					dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j]);
				}
			}
		}
//		for(ll i=0;i<s.size();i++)
//		{
//			for(ll j=0;j<t.size();j++)
//				cout<<dp[i][j]<<' ';
//				cout<<'\n';
//		}
		cout<<(s.size()-dp[s.size()-1][t.size()-1]+1)/2;
	}
}

