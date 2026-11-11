#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
ll n,m,k,s,a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1,j=1;i<=n;i++)
	{
		k+=a[i];
		while((i-j+1)*a[i]>k+m){k-=a[j];j++;}
		s=max(s,i-j+1);
	}
	cout<<s;
	return 0;
}
