#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n;
long long m,a[500010];
map<long long,int> mp,gs;

int ck(int id,long long z)
{
	int l=1,r=id-1,ans=id;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(((long long)(id-mid))*z-a[id-1]+a[mid-1]<=m)
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	 } 
	return ans;
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(mp.find(a[i])==mp.end()) mp[a[i]]=i;
		gs[a[i]]++;
		a[i]+=a[i-1];
	}
	for(auto v:mp)
	{
		int id=v.second;
		int tp=ck(id,v.first);
		ans=max(ans,id-tp+gs[v.first]);
	}
	cout<<ans;
	return 0;
}
