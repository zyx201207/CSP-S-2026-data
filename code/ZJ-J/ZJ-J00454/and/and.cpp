#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,x;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	} 
	int ans=0;
	for(int i=50;i>=0;i--){
		ans+=(1<<i);
		int cnt=0;
		for(int j=1;j<=n;j++){
			if((ans&a[j])==ans) cnt++;
		}
		if(cnt<m) ans-=(1<<i);
	}
	cout << ans;
	return 0;
}
