#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
int sum;
int ans;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		long long k;
		cin >> k;
		string d;
		cin >> d;
		for(int i=1;i<=k;i++)
		{
			s+=d;
		}
		sum+=k;
	}
	if(sum%2==0)
	{
		sum/=2;
		int j=sum+1;
		for(int i=sum-1;i>=0;i--)
		{
			if(s[i]==s[j])
			{
				j++;
				continue;
			}
			else
			{
				j++;
				ans++;
			}
			
		}
	}	
	else
	{
		sum/=2;
		int j=sum+1;
		for(int i=sum-1;i>=0;i--)
		{
			if(s[i]==s[j])
			{
				j++;
			
				continue;
				
			}
			else
			{
				ans++;
				j++;
			}
			
		}
	}
	cout<<ans;
	return 0;
	
}
