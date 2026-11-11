#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
int a[500005],cnt=1,ans=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mid=a[n/2+1];
	for(int i=n/2;i>=1;i--)
	{
		if(m-mid+a[i]>=0){
			m-=(mid-a[i]);	
			a[i]=mid;	
			cnt++;	
		}
	}
	for(int i=n/2+1;i<=n;i++)
	{
		if(m+mid-a[i]>=0){
			m-=(a[i]-mid);	
			mid=a[i];	
			ans++;	
		}
	}
	cout<<max(ans,cnt);
	return 0;
}