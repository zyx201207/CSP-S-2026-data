#include<bits/stdc++.h>
using namespace std;
const int N =5e5+10;
#define int long long
int n,m,cnt;
int a[N];
bool check(int mid)
{
	cnt = 0;
	for(int i= 1;i<mid;i++)
	{
		cnt+=a[mid]-a[i];
	}
	if(cnt<=m)
	{
		return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i= 1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l = 1,r =n+1;
	while(l<r)
	{
		int mid = (l+r)/2;
		if(check(mid))
		{
			l = mid+1;
			
		}
		else
			r= mid;
	} 
	cout<<l-1;
	return 0;
}

