#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n;
long long m;
long long a[maxn];
long long b[maxn]; 
bool check(int st,int ed)
{
	long long len=ed-st+1;
	if(a[ed]*len-(b[ed]-b[st-1])<=m)
		return 1;
	return 0;
}
int find(int x)
{
	int l=1,r=x;
	int ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid,x))
		{
			ans=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	return ans;
}
long long ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
//		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	for (int i=1;i<=n;i++)
		ans=max(ans,1ll*(i-find(i)+1));
	cout<<ans;
 } 
