#include<bits/stdc++.h>
#define ll long long
using namespace std;
using pa=pair<int,char>;
const int N=2e5+5;
int n;
ll cnt,k;
vector<pa> a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;char c;
		cin>>x>>c;
		a.push_back({x,c});
		k+=x;
	}
	int l=0,r=n-1;
	while(l+1<=r)
	{
		int x1=a[l].first;char c1=a[l].second;
		int x2=a[r].first;char c2=a[r].second;
		if(c1==c2)
		{
			if(x1>x2)
			{
				a[l].first-=x2;
				r--;
				continue;
			}
			else if(x1<x2)
			{
				a[r].first-=x1;
				l++;
				continue;
			}
			else
			{
				l++,r--;
				continue;
			}
		}
		if(x1>x2)
		{
			a[l].first-=x2;
			cnt+=x2;
			r--;
			continue;
		}
		else if(x1<x2)
		{
			a[r].first-=x1;
			cnt+=x1;
			l++;
			continue;
		}
		else
		{
			l++,r--;
			cnt+=x1;
			continue;
		}
		
	}
	cout<<cnt;
	return 0;
}
