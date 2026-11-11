#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=5e5+5;
int n,m;
int a[N];
int pre[N];
bool check(int ans)//check:选择一组区间(len=ans)，使得最大值-a[i]的和的值最小 
{
	for(int i=1;i<=n-ans+1;i++)
	{
		//求[l,r] 使得所有元素变成maxn的花费公式：最大值*len-区间和 
		int maxn=a[i+ans-1];
		int sum=pre[i+ans-1]-pre[i-1];
		if(maxn*ans-sum<=m)
		{
			return true;
		}
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n>>m;
	int sum=0;
	int temp2=0;
	for(int i=1;i<=n;i++)
	{
		cin >>a[i];
		temp2+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i];
	}
	int l=0,r=n+1;
	int ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout <<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
