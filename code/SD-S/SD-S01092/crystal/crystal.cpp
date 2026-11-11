#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=500005;
int n,m,ans,a[N],s[N];
	signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+a[i]-a[i-1];
	}
	int l=1,r=0,sum=0;
	while(r<=n){
		r++;
		sum+=(s[r]-s[r-1])*(r-l);
		while(sum>m){
			l++;
			sum-=s[r]-s[l-1];
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
