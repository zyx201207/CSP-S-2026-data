#include<bits/stdc++.h>
#define int long long
using namespace std;
int b[500005],a[500005],c[500005];
int l,r,maxx=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	l=1,r=1;
	int now=0;
	for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++){
		now=now+(b[i]*(r-l+1));
		r++;
		while(now>m){
			now=now-(a[r]-a[l]);
			l++; 
		}
		maxx=max(maxx,r-l+1);
	}
	cout<<maxx;
	return 0;
}
