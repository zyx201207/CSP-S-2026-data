#include<bits/stdc++.h>
using namespace std;
long long a[500005],m,cnt,maxx=1;
int n,ans=1,l=1;
int main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		cnt=cnt+(a[i]-a[i-1])*(i-l);
		ans++;
		while(cnt>m)
		{
			cnt-=(a[i]-a[l]);
			l++,ans--;
		}
		if(ans>maxx)
		{
			maxx=ans;
		}
	}
	cout<<maxx;
	return 0;
}
