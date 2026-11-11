#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int N=2e5+10;
ll a[N];
char cc[N];
ll ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>cc[i];
	}
	int j=n,i=1;
	while(i<=n&&i<j)
	{
		ll ca=min(a[i],a[j]);
		if(cc[i]!=cc[j]) ans+=ca;
		a[i]-=ca;
		a[j]-=ca;
		if(a[i]==0) i++;
		else j--;
	}
	cout<<ans;
	return 0;
 } 

