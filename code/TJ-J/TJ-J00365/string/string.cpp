#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200005];
char c[200005];
int ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	int l=1,r=n;
	while(l!=r)
	{
		if(a[l]>=a[r]&&c[l]!=c[r])
		{
			ans+=a[r];
			a[l]-=a[r];
			r--;
		}
		else if(a[l]>=a[r]&&c[l]==c[r])
		{
			a[l]-=a[r];
			r--;
		}
		else if(a[l]<a[r]&&c[l]!=c[r])
		{
			ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		else if(a[l]<a[r]&&c[l]==c[r])
		{
			a[r]-=a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
