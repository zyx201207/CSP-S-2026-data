#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>v;
int lst[500010];
int cnt[500010],cf[500010],k[500010];
int n,m;
int cn=1;
void s(int pos)
{
	if(pos>=cn)
	{
		cf[pos]++;
		return;
	}
	if(pos==lst[k[pos]])
	{
		cnt[k[pos]]++;
		s(pos+1);
	}else{
		s(lst[k[pos]]);
	}
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		lst[k[i]]=i;
	}
	for(int i=n;i>=1;i--)
	{
		if(lst[k[i]]!=i)
		{
			cn=i+1;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		s(i);
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=cf[i];
		cnt[k[i]]+=sum;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	return 0;
}

