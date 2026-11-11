#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ans;
ll n,m;
ll pre[500100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
//	for(int i=0;i<n;i++)
//		for(int j=i;j<n;j++)
//		{
//			if(a[j]*(j-i)-(pre[j-1]-pre[i]+1)<=m)
//				ans=max(ans,j-i+1);
//			else break;
//		}
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n;
		int mid;
		while(l<r)
		{
			mid=(l+r)>>1;
//			cout<<"i="<<i<<"  mid="<<mid<<"  l="<<l<<"  r="<<r;
			if(a[mid]*(mid-i)-(pre[mid-1]-pre[i-1])<=m)
			{
				ans=max(ans,mid-i+1);
				l=mid+1;
			}
			else r=mid;
//			cout<<"   ans="<<ans<<'\n';
		}
		if(a[l]*(l-i)-(pre[l-1]-pre[i-1])<=m) ans=max(ans,l-i+1);
	}
	cout<<ans;
}

/*
6 1
1 2 1 1 2 2 
*/
