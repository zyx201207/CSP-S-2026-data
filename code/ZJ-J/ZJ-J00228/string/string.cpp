#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n;
long long ans=0,a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]!=c[r])
		{
			if(a[l]<a[r])
				ans+=a[l],a[r]-=a[l],l++;
			else ans+=a[r],a[l]-=a[r],r--;
			
		}
		else 
		{
			if(a[l]<a[r])
				a[r]-=a[l],l++;
			else a[l]-=a[r],r--;
		}
		if(a[l]<=0) l++;
		if(a[r]<=0) r--;
	}
	cout<<ans;
	return 0;
}