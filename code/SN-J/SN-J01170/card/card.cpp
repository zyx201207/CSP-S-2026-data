//西安市高新第二初级中学 八年级16班 SN-J01170 杨博 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[200005],a[200005];
int n,m,l;
int res[300005];
queue<int>b;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	l=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b.push(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int s=b.front();
		b.pop();
		for(int j=n;j>0;j++)
		{
			if(s==a[j])
			{
				l-=j;
			}
			else
			{
				l++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		res[a[i]]++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<res[i];
	}
	return 0;
}
