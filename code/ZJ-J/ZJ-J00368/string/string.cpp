#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int,char>s[200005],k;
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,ans=0,r=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>s[i].first>>s[i].second;
	int i=0,j=n-1;
	while(i<=j)
	{
		if(k.first<=0)
		{
			if(s[i].second!=k.second)ans+=min(-k.first,s[i].first);
			k.first+=s[i].first;
			if(k.first>=0)k.second=s[i].second;
			i++;
		}
		else
		{
			if(s[j].second!=k.second)ans+=min(k.first,s[j].first);
			k.first-=s[j].first;
			if(k.first<=0)k.second=s[j].second;
			j--;
		}
	}
	return cout<<ans,0;
}