#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[500050],pre[500050];
int n,m;
bool check(int x)
{
	for(int i=1;i<=n-x+1;i++)
	{
		int l=i,r=i+x-1;
		if(x*a[r]-(pre[r]-pre[l-1])<=m)return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i];
	}
	int lt=1-1,rt=n+1;
	while(lt+1<rt)
	{
		int mid=(lt+rt)/2;
		if(check(mid)==1)lt=mid;
		else rt=mid;
	}
	cout<<lt;
	return 0;
}
