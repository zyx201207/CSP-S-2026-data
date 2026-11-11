#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 100;
int cnt[N] ;
char ch[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> cnt[i] >> ch[i];
	}
	int l = 1, r = n;
	int ans = 0;
	while(l + 1 <= r){
		if(ch[l] == ch[r]){
			if(cnt[l] > cnt[r]){
				cnt[l] -= cnt[r];
				r--;
			}else if(cnt[l] < cnt[r]){
				cnt[r] -= cnt[l];
				l++;
			}else if(cnt[l] == cnt[r]){
				l++;
				r--;
			}
		}else{
			if(cnt[l] > cnt[r]){
				ans += cnt[r];
				cnt[l] -= cnt[r];
				r--;
			}else if(cnt[l] < cnt[r]){
				ans += cnt[l];
				cnt[r] -= cnt[l];
				l++;
			}else if(cnt[l] == cnt[r]){
				ans += cnt[l];
				l++;
				r--;
			}
		}
	}
	cout << ans <<"\n";
	return 0;
}
