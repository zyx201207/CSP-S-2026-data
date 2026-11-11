#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,sum[N],s[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	sort(s+1,s+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+s[i];
	for(int l=1,r=1;l<=n;l++){ 
		while(r<=n&&s[r]*(r-l+1)-(sum[r]-sum[l-1])<=m)++r;
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
}

