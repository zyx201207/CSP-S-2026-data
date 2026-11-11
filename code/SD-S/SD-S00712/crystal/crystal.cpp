#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int sumn[500005];
int minn,maxn;
int n,m;
int ans;
vector<int> c;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sumn[i]=sumn[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-sumn[i]+sumn[mid-1]<=m){
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0; 
}
