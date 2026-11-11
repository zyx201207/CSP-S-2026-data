#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans=0,fin_ans=0;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=0;
	for(int i=2;i<=n;i++)
	{
		fin_ans=max(fin_ans,ans);
		ans=1;
		for(int j=i;j<=n;j++)
		{
			if(a[j]==a[j-1])
			{
				ans++;
			}
			else if(m>=(j-1)*(a[j]-a[j-1]))
			{
				ans++;
				m-=(j-1)*(a[j]-a[j-1]);
			}
			else
			{
				break;
			}
		}
	}
	cout<<fin_ans;	
}
