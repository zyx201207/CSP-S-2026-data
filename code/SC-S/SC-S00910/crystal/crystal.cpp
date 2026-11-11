#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,ans=0,cnt=0;
	ll m,num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=0;
	for(int i=1;i<=n;i++)
	{
		int las=0;
		while(l<i-1&&cnt*(a[i]-a[i-1])+num>m)
		{
			num-=a[i-1]-a[l];
			l++;
			cnt--;
		} 
		num+=cnt*(a[i]-a[i-1]);
		cnt++;
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}