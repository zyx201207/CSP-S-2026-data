#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=500005;
ll m,a[N],mk;
int n,ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++)
	//	cout<<a[i];
	int p1=1,p2=1;
	while(a[p2]==a[p2+1])
		p2++;
	ans=p2;
	mk=m;
	while(p2<n)
	{
		p2++;
		mk-=(a[p2]-a[p2-1])*(p2-p1);
		//cout<<p2<<'|'<<mk<<' ';
		while(a[p2]==a[p2+1]&&p2<=n)
			p2++;
		while(mk<0&&p1<p2)
		{
			mk+=a[p2]-a[p1];
			p1++;
		}
		ans=max(ans,p2-p1+1);
	}
	cout<<ans;
	return 0;
}
