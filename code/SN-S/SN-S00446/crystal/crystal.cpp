//ZHS 00446 
#include<bits/stdc++.h>
#define int long long
#define maxn 500005
using namespace std;
int n,a[maxn],m,ans; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		a[i]+=a[i-1];
	for(int i=1;i<=n;i++){
		int now=0,mn=(a[i]-a[i-1]);
		for(int j=1ll<<20;j>=1;j>>=1){
			if(now+j<i&&(now+j+1)*mn-(a[i]-a[i-now-j-1])<=m)
				now+=j;
		}
		ans=max(ans,now);
	}
	cout<<ans+1;
	return 0;
}
