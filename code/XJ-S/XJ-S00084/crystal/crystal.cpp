#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;

int a[N],n,m;
int ans = 0; 
bool check(int x,int y){
	int cost = 0;
	for(int i = y;i >= x;i--){
		cost += a[y] - a[i];
	}
	if(cost <= m){
		return 1;
	}
	else{
		return 0;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		int now_ans = 0;
		int l = 1,r = i;
		while(l<=r){
			int mid = (l+r)>>1;
			if(check(mid,i)){
				now_ans = mid;
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		ans = max(ans,i - now_ans+1);
		//cout << now_ans << " ";
	}
	cout << ans;
	return 0;
} 
