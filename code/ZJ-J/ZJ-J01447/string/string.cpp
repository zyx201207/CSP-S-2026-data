#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define endl "\n"
using pii=pair<int,int>;
const int N=2e5+10;
int n;
ll a[N];
char c[N];
ll ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	fast;
// aabbcc
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int w;
	if(n%2==0)
	{
		w=n/2;
	}
	else
	{
		w=n/2+1;
	}
	int b[N];
	for(int i=1;i<=w;i++)
	{
		if(c[i]!=c[n-i+1])
		{
			ans+=max(a[i],a[n-i+1]);
		}
	}
	cout<<ans;
	return 0;	
}