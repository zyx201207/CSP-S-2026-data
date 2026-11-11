#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans;
ll m;
ll a[N];
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int j=1;
	for(int i=1;i<=n;i++)
	{
		for(int k=j+1;k<=n;k++)
		{
			if(m>=a[i]-a[k]) m-=a[i]-a[k],j++;
			else break;
		}
		ans=max(ans,j-i+1);
		m+=(a[i]-a[i+1])*(j-i+1);
	}
	cout<<ans;
	return 0;
}

