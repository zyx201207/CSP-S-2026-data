// crystal
#include<bits/stdc++.h>
bool Mst;
using namespace std;
using ll=long long;
#define int ll
using pii=pair<int,int>;
const int N=1e6+5;
int a[N];
bool Med;
signed main()
{
//	cerr<<abs((&Med)-(&Mst))/1024.0/1024.0<<" MB"<<endl;
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int r=1,l=1,s=0;r<=n;r++)
	{
		s+=a[r];
		while(a[r]*(r-l+1)-s>m) s-=a[l++];
		ans=max(ans,r-l+1);
	}
	cout<<ans<<"\n";
//	cerr<<clock()<<endl;
}

/*
5 5
1 2 4 8 9

3

5 8
-3 -1 2 2 7

4
*/

// NOIP2025 zj 2= rk1 到此一游
