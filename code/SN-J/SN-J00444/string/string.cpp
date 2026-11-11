#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	while(1)
	{
		if(l>=r) break;
		if(a[l]<a[r])
		{
			if(c[l]==c[r]) a[r]-=a[l],l++;
			else ans+=a[l],a[r]-=a[l],l++;
		}
		else if(a[l]>a[r])
		{
			if(c[l]==c[r]) a[l]-=a[r],r--;
			else ans+=a[r],a[l]-=a[r],r--;
		}
		else 
		{
			if(c[l]==c[r]) a[l]-=a[r],l++,r--;
			else ans+=a[l],a[l]-=a[r],l++,r--;
		}
	}
	cout<<ans;
	return 0;
}
