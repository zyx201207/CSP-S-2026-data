#include<bits/stdc++.h>
using namespace std;
using llt=long long;
const int maxn=5e5+5;
int n,ans;
llt m,a[maxn];
int main()
{
//	system("fc crystal4.ans crystal.out");
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	llt sum=0;
	for(int l=1,r=1;r<=n;r++)
	{
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m)
		{
			sum-=a[r]-a[l];
			l++;
		}
		ans=max(r-l+1,ans);
	}
	cout<<ans;
	return 0;
}
