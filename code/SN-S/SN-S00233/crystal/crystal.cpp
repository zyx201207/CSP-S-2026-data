#include<bits/stdc++.h>
#define PI "crystal"
#define FI freopen(PI".in","r",stdin)
#define FO freopen(PI".out","w",stdout)
#define ll  long long
using namespace std;
const int N=5e5+5;
ll n,m,ans;
ll a[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	FI;FO;
	cin>>n>>m;
	int aa=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int av=a[1];
		if(av==a[i]) aa++;
	}
	if(aa==n)
	{
		cout<<n;
		return 0;
	}
	cout<<0;
	return 0;
}
