#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1000010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sy = m;
	int pt = 0;
	for(int i = n;i>=1;i--){
		if(sy-(a[n]-a[i])<0){
			pt = i;
			break;
		}
		sy -= a[n] - a[i];
	}
	int ans = -1;
	ans = max(ans,n-pt);
	for(int i = n-1;i>=1;i--){
		int cz = a[i+1]-a[i];
		sy += cz*(i-pt);
		while(sy-(a[i]-a[pt])>=0&&pt>=1){
			sy -= a[i]-a[pt];
			pt--;
		}
		ans = max(ans,i-pt);
		if(pt <1)break;
	}
	cout<<ans;
	return 0;
}