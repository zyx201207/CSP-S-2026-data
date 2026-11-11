#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],q[500005];
long long sum(int l,int r){return q[r]-q[l-1];}
bool check(int x,int y)
{
	if((y-x+1)*a[y]-sum(x,y)<=m)return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){q[i]=q[i-1]+a[i];}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid = (l+r)>>1;
			if(check(mid,i)) r=mid;
			else           l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
