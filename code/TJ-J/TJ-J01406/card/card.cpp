#include<bits/stdc++.h>
using namespace std;
vector<int> a,cnt;
stack<int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		cnt[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			cnt[a[j]]++;
			if((cnt[a[j]]-i)%2==0)
			{
				cnt[a[j]]=1+i;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i];
	}
	return 0;
}
