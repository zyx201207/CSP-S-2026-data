#include<bits/stdc++.h>
#define int long long
#define mod 998244353
#define mp make_pair
using namespace std;

int n,m,a[500005],pre[500005];

signed main(){
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);int ans=0;
	for(int i=1;i<=n;i++)pre[i]=a[i]+pre[i-1];
	for(int i=1,j=1;i<=n;i++){
		while(j<i&&a[i]*(i-j+1)-(pre[i]-pre[j-1])>m)j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
}

