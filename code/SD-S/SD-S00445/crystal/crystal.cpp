#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define ull unsigned long long
#define ll long long
#define endl '\n'
using namespace std;
const int N=5e5+7;
__int128 s[N],op=1;
ll m,a[N];
int n,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	IO;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		a[i]=x;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(int l=1,r=1;r<=n;r++)
	{
		while(op*a[r]*(r-l+1)-s[r]+s[l-1]>op*m) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}

