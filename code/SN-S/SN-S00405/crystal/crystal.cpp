#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int a[N],n,m,ans,sum[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int t=1;
	for(int i=1;i<=n;i++){
		while(t+1<=i&&(a[i]*(i-t+1)-(sum[i]-sum[t-1]))>m)++t;
		ans=max(ans,i-t+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
3

5 8
-3 -1 2 2 7
4
*/
