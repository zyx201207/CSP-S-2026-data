#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define fr(x) freopen(#x".in","r",stdin)
#define fw(x) freopen(#x".out","w",stdout)
using namespace std;
using db=double;
using ll=long long;
using ull=unsigned long long;
using PI=pair<int,int>;
const int N=2e5+5;
int n,m;
int cnt[40];
ll ans;
ll a[N];
int main()
{
	fr(and);
	fw(and);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		for(int j=0;j<=31;j++)
			if((a[i]>>j)&1) 
				cnt[j]++;
	}
	for(int i=1;i<=n;i++) 
		for(int j=0;j<=31;j++)
			if((a[i]>>j)&1&&cnt[j]<m)
				a[i]-=(1ll<<j);
	sort(a+1,a+n+1,greater<ll>());
	for(int i=1;i<=m;i++) a[1]&=a[i];
	cout<<a[1]<<'\n';
	return 0;
}