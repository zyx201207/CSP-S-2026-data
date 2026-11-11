#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,ans;ll m,w[500005],s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>w[i];
	sort(w+1,w+n+1);
	for(int i=1,l=1;i<=n;i++){
		s[i]=s[i-1]+w[i];
		while(l<i&&1ll*w[i]*(i-l+1)-(s[i]-s[l-1])>m)l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
}