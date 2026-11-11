#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ll mx=-1;
	for(int i=1;i<=n;i++) {
		ll c=0,tmp=0;
		for(int j=i;j>=1;j--) {
			if(c+abs(a[i]-a[j])<=m) c+=abs(a[i]-a[j]),tmp++;
			else break;
		}
		mx=max(mx,tmp);
	}
	cout<<mx;
	return 0;
}