#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+10;
int n,m;
int a[N];
bool cmp(int a,int b)
{
	return a>b;
}
int ans;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++)
	{
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}

