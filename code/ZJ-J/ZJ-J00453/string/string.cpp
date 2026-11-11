#include <bits/stdc++.h>
using namespace std;
long long n,ans,pos1,pos2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	vector<pair<int,char>> a(n+1);
	for (int i=1; i<=n; i++)
		cin>>a[i].first>>a[i].second;
	pos1=1,pos2=n;
	while (pos1<pos2)
	{
		if (a[pos1].second!=a[pos2].second)
			ans+=min(a[pos1].first,a[pos2].first);
		if (a[pos1].first>a[pos2].first) a[pos1].first-=a[pos2].first,pos2--;
		else if (a[pos1].first<a[pos2].first) a[pos2].first-=a[pos1].first,pos1++;
		else if (a[pos1].first=a[pos2].first) pos1++,pos2--;
	}
	cout<<ans;
	return 0;
}