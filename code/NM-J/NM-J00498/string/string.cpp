#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int a[MAXN];
char c[MAXN];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=1;
	int r=n;
	while(l<r)
	{
		int v=min(a[l],a[r]);
		if(c[l]!=c[r])
		{
			ans+=v;
		}
		a[l]-=v;
		a[r]-=v;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
}
