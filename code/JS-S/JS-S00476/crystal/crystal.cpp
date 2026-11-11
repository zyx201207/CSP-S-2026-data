#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,a[500005],num[500005];
bool check(int x,int y){
	return m >= (a[y]*(y-x+1))-(num[y]-num[x-1]);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		num[i] = num[i-1] + a[i];
	}
	for(int i = 1;i<=n;i++){
		int l = 1,r = i;
		while(l < r){
			int mid = (l+r)/2;
			if(check(mid,i)){
				r = mid;
			}else{
				l = mid+1;
			}
		}
		ans = max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}