#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],mx=-1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	bool AB=1;
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])
		{
			AB=0;
			break;
		}
	}
	if(AB)
	{
		ll sum=1,gc=a[2]-a[1];
		for(int i=1;i<n;i++)
		{
			m-=gc*i;
			if(m<0) break;
			sum++;
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		ll nd=0,s=1;
		for(int j=i+1;j<=n;j++)
		{
			nd+=(a[j]-a[j-1])*(j-i);
			if(nd>m) break;
			s++;
		}
		mx=max(mx,s);
		//cout<<s<<"\n";
	}
	cout<<mx;
	return 0;
}
