#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a1[N],a2[N],l=1,r=1,ans;
char c1[N],c2[N];
signed main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;r=1;
	for (int i=1;i<=n;i++)
	{
		cin>>a1[i]>>c1[i];
		a2[n-i+1]=a1[i];
		c2[n-i+1]=c1[i];
	}
	while (l<=n&&r<=n)
	{
		if (c1[l]==c2[r])
		{
			if (a1[l]>a2[r]) a1[l]-=a2[r],a2[r]=0;
			else a2[r]-=a1[l],a1[l]=0;
			if (a1[l]==0) l++;
			if (a2[r]==0) r++;
		}
		else
		{
			if (a1[l]>a2[r]) ans+=a2[r],a1[l]-=a2[r],a2[r]=0;
			else ans+=a1[l],a2[r]-=a1[l],a1[l]=0;
			if (a1[l]==0) l++;
			if (a2[r]==0) r++;
		}
	}
	cout<<ans/2;
	return 0;
}
