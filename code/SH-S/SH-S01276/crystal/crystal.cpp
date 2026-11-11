#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N=5e5+5;

int a[N],m,n;

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int cnt=0,sum=0,ans=0;
	for(int i=1;i<=n;i++) {
		if(i!=1) sum+=a[i-1],cnt++;
		while(a[i]*cnt-sum>m) cnt--,sum-=a[i-cnt];
		ans=max(ans,cnt);
	}
	cout<<ans+1<<'\n';
	return 0;
}
