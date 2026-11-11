#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7;
ll m,a[N],c[N],ans=1;	
int n;
int main()
{
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
 	cin.tie();
 	cin>>n>>m;
 	for(int i=1;i<=n;i++) cin>>a[i];
 	sort(a+1,a+1+n);
 	for(int i=1;i<=n;i++) c[i]=a[i]+c[i-1];
 	for(int i=1;i<=n;i++)
	{
		long long l=1,r=i;
		while(l<r)
		{
			long long mid=(l+r+1)/2;
			if(a[i]*(mid-1)-c[i-1]+c[i-mid]>m) r=mid-1;
			else l=mid;
		}
		ans=max(ans,l);	
	}
	cout<<ans;
}