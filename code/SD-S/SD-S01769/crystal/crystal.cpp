#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,ans=1,a[500010],pre[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int l=1;
	for(int i=1;i<=n;i++){
		while((pre[i]-pre[l-1]+m)<a[i]*(i-l+1))l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}

