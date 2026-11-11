#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sin signed
#define endl "\n"
int n;
int a[200010],len;
char c[200010];
sin main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i]>>c[i];
		len+=a[i];
	}
	int l=1,r=n,tot=1,ans=0;
	while(tot<=len/2)
	{
		if(c[l]==c[r])
		{
			if(a[l]<=a[r])
			{
				tot+=a[l];
				a[r]-=a[l];
				l++;
			}
			else
			{
				tot+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
		else
		{
			if(a[l]<=a[r])
			{
				tot+=a[l];
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}
			else
			{
				tot+=a[r];
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
