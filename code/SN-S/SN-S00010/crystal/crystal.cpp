#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+10;
ll m,a[maxn],ch[maxn];
int n,ans[maxn];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
		ch[i]=a[i+1]-a[i];
	for(int i=1;i<n;i++)
	{
		ll chz=0,sum=0;
		int j=i;
		do
		{
			chz+=ch[j-1];
			sum+=chz;
		}while(sum<=m&&(j--)>0);
		ans[i]=i-j;
	}
	int ans1=0;
	for(int i=0;i<n;i++)ans1=max(ans1,ans[i]);
	cout<<ans1+1;
	return 0;
}
