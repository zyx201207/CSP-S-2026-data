#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2145140];
void solve1()
{
	int n,k,m,lst;cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	m=a[2]-a[1];
	int err=k/m;
	if(err==0||err==1)cout<<0<<"\n";
	else if(n<2*err-1)cout<<0<<"\n";
	else cout<<n-2*err+1<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
		ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--)
	{
		//if(c==11||c==12)
		solve1();
	}
}
