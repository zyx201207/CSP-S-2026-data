#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
#define all(x) (x.begin(),x.end())
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define DEP(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=5e5+10;
ll a[maxn];
ll q[maxn];
int n,m;
bool check(int x)
{
	ll mn=2e18;
	REP(i,1,n-x+1)
	{
		ll l=i,r=i+x-1;
		ll c=a[r]*(r-l+1)-(q[r]-q[l-1]);
		mn=min(mn,c);
	}
	return mn<=m;
}
signed main()
{
	Ios();
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	REP(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	REP(i,1,n) q[i]=q[i-1]+a[i];
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<"\n";
	return 0;
}
//12min pretest passed(4)
//wofule,haoxiangshi 275pts