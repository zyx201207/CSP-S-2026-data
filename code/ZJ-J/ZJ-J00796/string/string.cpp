#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll n;
ll a[N];
char c[N];
ll l,r;
ll ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	l=1,r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	while(l<=r)
	{
		if(c[l]!=c[r])
		{
			if(a[r]>a[l])
			{
				a[r]-=a[l];
				ans+=a[l];
				a[l]=0;
				l++;
			}else if(a[l]==a[r]){
				ans+=a[l];
				a[r]=0;
				a[l]=0;
				l++;
				r--;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				ans+=a[r];
				a[r]=0;
				r--;
			}
		}else{
			if(a[l]<a[r])
			{
				a[r]-=a[l];
				a[l]=0;
				l++;
			}else if(a[l]==a[r])
			{
				a[l]=a[r]=0;
				l++,r--;
			}else if(a[l]>a[r])
			{
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
