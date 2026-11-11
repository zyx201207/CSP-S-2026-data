#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],cnt1,cnt2,ans;
string c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	cnt1=1;
	cnt2=n;
	while(cnt1<cnt2)
	{
		if(c[cnt1]!=c[cnt2])
		{
			if(a[cnt1]>=a[cnt2])
			{
				ans+=a[cnt2];
				a[cnt1]-=a[cnt2];
				cnt2--;
			}
			else
			{
				ans+=a[cnt1];
				a[cnt2]-=a[cnt1];
				cnt1++;
			}
		}
		else
		{
			if(a[cnt1]>=a[cnt2])
			{
				a[cnt1]-=a[cnt2];
				cnt2--;
			}
			else
			{
				a[cnt2]-=a[cnt1];
				cnt1++;
			}
		}
	}
	cout<<ans;
	return 0;
}