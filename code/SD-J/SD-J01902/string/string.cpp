#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans,n,a[200000];
string s[200000];
signed main()
{
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
	for(int i=1,j=n;i<j;)
	{
		if(a[i]==a[j])
		{
			if(s[i]!=s[j])
			{
				ans+=a[i];
				i++,j--;
			}
			else i++,j--;
		}
		else if(a[i]>a[j])
		{
			if(s[i]!=s[j]) ans+=a[j];
			a[i]-=a[j],j--;
		}
		else
		{
			if(s[i]!=s[j]) ans+=a[i];
			a[j]-=a[i],i++;
		}
	}
	cout<<ans;
	return 0;
}
