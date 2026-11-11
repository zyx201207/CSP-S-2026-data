#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mk make_pair
bool ST;
int n,a[200010];
char c[200010];
bool ED;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	ll ans=0,l=a[1],r=a[n];
	int i=1,j=n;
	while(i<j)
	{
		if(c[i]!=c[j])ans+=min(l,r);
		int mi=min(l,r);
		l-=mi,r-=mi;
		if(l==0)l=a[++i];
		if(r==0)r=a[--j];
//		cerr<<i<<" "<<j<<" "<<ans<<"\n";
	}
	cout<<ans;
//	cerr<<"\nTime used: "<<1.0*clock()/CLOCKS_PER_SEC*1000<<"ms\n";
//	cerr<<"Memory used: "<<abs(&ST-&ED)/1024.0/1024.0<<"mb\n";
	return 0;
}
