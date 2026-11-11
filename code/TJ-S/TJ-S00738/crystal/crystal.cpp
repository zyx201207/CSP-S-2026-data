#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mk make_pair
bool ST;
int n;
ll m,a[500010];
bool ED;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	int ans=0;
	ll sum=0;
	for(int i=1,j=1;i<=n;++i)
	{
		while((i-j)*a[i]-sum>m)
		{
			sum-=a[j];
			++j;
		}
		ans=max(ans,i-j+1);
		sum+=a[i];
//		cerr<<i<<" "<<j<<"\n";
	}
	cout<<ans;
//	cerr<<"\nTime used: "<<1.0*clock()/CLOCKS_PER_SEC*1000<<"ms\n";
//	cerr<<"Memory used: "<<abs(&ED-&ST)/1024.0/1024.0<<"mb\n";
	return 0;
}//14:54 100pts
