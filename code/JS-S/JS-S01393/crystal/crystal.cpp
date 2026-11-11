#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N];
bool check(int x)
{
    int sum=0;
    for(int i=1;i<x;i++) sum+=a[i];
    for(int i=x;i<=n;i++)
    {
        sum+=a[i]-a[i-x];
        if(x*a[i]-sum<=m) return 1;
    }
    return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n+1;
	while(l+1<r)
    {
        int mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }
    cout<<l;
	return 0;
}
