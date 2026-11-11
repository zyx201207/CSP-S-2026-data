#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long qz[500010];
bool ch(int x){
	for(int i=x;i<=n;i++){
		if(a[i]*(x-1)-qz[i-1]+qz[i-x]<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) qz[i]=qz[i-1]+a[i];
	int l=1,r=n;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(ch(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout << ans;
	return 0;
}
