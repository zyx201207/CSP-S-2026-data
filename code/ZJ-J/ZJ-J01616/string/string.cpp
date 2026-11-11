#include<bits/stdc++.h>
using namespace std;
int n,a[200001];
long long ans;
char s[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	int ll=1,rr=n;
	while(ll<rr)
	{
		if(a[ll]==a[rr])
		{
			if(s[ll]!=s[rr])
			{
				ans+=a[ll];
			}
			ll++;rr--;
		}
		else
		{
			if(s[ll]!=s[rr])
			{
				ans+=min(a[ll],a[rr]);
			}
			if(a[ll]>a[rr])
			{
				a[ll]-=a[rr];
				rr--;
			}
			else
			{
				a[rr]-=a[ll];
				ll++;
			}
		}
	}
	cout<<ans;
}