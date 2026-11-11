#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int mx=0;
	for(int i=1;i<=n;i++){
		int ans=1;
		int dm=m;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=m){
				ans++;
				m-=(a[i]-a[j]);
			}else break;
		}
		m=dm;
		mx=max(mx,ans);
	}
	cout<<mx;
	return 0;
}