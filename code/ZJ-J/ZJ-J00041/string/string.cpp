#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,sum;
pair<ll,char> q[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>q[i].first>>q[i].second;
	}
	for(ll i=1,j=n;i<j;)
	{
		if(q[i].first<q[j].first)
		{
			if(q[i].second!=q[j].second)sum+=q[i].first;
			q[j].first-=q[i].first;
			q[i].first=0;
			i++;
		}
		else if(q[i].first>q[j].first)
		{
			if(q[i].second!=q[j].second)sum+=q[j].first;
			q[i].first-=q[j].first;
			q[j].first=0;
			j--;
		}
		else
		{
			if(q[i].second!=q[j].second)
			{
				sum+=q[j].first;
				q[j].first=0,q[i].first=0;
			}
			i++,j--;
		}
	}
	cout<<sum;
	return 0;
}
