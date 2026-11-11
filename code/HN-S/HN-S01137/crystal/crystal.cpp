#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N];
long long cnt=0,ans=0,b=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];	
		cnt+=abs(a[i]); 
	}
	cnt/=n;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=cnt)
		{
			b++;
			ans+=cnt-abs(a[i]);
		} 
	}
	if(ans>m) cout<<b-1;
	else cout<<b;
	return 0;
}
