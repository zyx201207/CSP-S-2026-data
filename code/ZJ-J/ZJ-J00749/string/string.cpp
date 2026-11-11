#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
char op[N];
int n,ans,a[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>op[i];
	int l=1,r=n;
	int t1=a[1],t2=a[n];
	char op1=op[1],op2=op[n];
	while(l<r)
	{
		if(a[l]>=a[r])
		{
			if(op[l]!=op[r]) ans+=a[r];
			a[l]-=a[r],a[r]=0;
		}
		else
		{
			if(op[l]!=op[r]) ans+=a[l];
			a[r]-=a[l],a[l]=0;
		}
		if(a[l]==0) ++l;
		if(a[r]==0) --r;
	}
	cout<<ans;
	return 0;
}