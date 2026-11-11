#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,a[500005],b[500005],maxx=1;
map<int,int>mp;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
		maxx=max(maxx,mp[a[i]]);
	}
	sort(a+1,a+n+1);
	int mid=a[((n+1)/2)];
	for(int i=1;i<=(n+1)/2;i++)
	{
		if(a[i]!=0)
		b[i]=mid-a[i];
	}
	int sum=0;
	sort(b+1,b+((n+1)/2)+1);
	int cnt=mp[mid]-1;
	int i=1;
	int f=0;
	if(m>0)
	{
		while(1)
		{
			if(m<0)
			{
				break;
			}
			if(b[i]>0)
			{
				m-=b[i];
				cnt++;
			}
			i++;
			if(i>=1000000)
			{
				break;
				f=1;
			}
		}
	}
	if(f==0)
	{
		cout<<max(cnt,maxx);
	}
	else
	{
		cout<<maxx;
	}
	return 0;
}

