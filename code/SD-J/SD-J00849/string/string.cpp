#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,char> > v;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,sum=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		scanf("%lld %c",&a,&c);
		sum+=a;
		v.push_back({a,c});
	}
	int ans=0;
	int l=0,r=n-1,i=0,j=sum-1;
	while(i<j)
	{
		if(v[l].second!=v[r].second) ans++;
		v[l].first--,v[r].first--;
		if(v[l].first==0) l++;
		if(v[r].first==0) r--;
		i++,j--;
	}
	printf("%lld",ans);
	return 0;
}
