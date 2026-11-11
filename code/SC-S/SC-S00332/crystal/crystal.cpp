#include <bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		int cnt=m,cnt1=0;
		for(int j=1;j<=n;j++){
			if(j==i){
				continue;
			}
			if(a[j]<=a[i]){
				cnt1++;
				cnt-=(a[i]-a[j]);
			}
			if(cnt<0){
				cnt1--;
				break;
			}
		}
		ans=max(cnt1+1,ans);
	}
	cout << ans;
	return 0;
}