#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,ans=1;
int a[N],pre[N];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		while(j<=i&&(i-j+1)*a[i]-pre[i]+pre[j-1]>m)j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}

