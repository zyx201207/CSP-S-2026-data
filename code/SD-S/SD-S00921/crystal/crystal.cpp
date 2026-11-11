#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans=1;
ll m,a[N],c[N],sum[N],suma[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)c[i]=a[i+1]-a[i];
	for(int i=1;i<n;i++)sum[i]=sum[i-1]+1ll*i*c[i],suma[i]=suma[i-1]+c[i];
	int r=1;
	for(int i=1;i<n;i++){
		while(r+1<n&&sum[r+1]-sum[i-1]-1ll*(i-1)*(suma[r+1]-suma[i-1])<=m)r++;
		ans=max(ans,r-i+2);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
