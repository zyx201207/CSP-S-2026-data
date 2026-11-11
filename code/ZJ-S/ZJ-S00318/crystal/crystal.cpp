#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,i,l,r,maxx;
	long long m;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	maxx=1;
	l=1;
	for(r=2;r<=n;r++)
	{
		m-=(a[r]-a[r-1])*(r-l);
		while(m<0)
		{
			m+=a[r]-a[l];
			l++;
		}
		maxx=max(maxx,r-l+1);
	}
	cout<<maxx;
	return 0;
}