#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n;
ll m , a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	sort(a + 1 , a + n + 1);
	ll sum = 0 , cnt = 1 , l = 1 , maxn = 0;
	for(int i = 2;i <= n;i++){
		if(sum + (a[i] - a[i - 1]) * cnt > m){
			while(l < i){
				sum -= (a[i - 1] - a[l]);
				l++;
				cnt--;
				if(sum + (a[i] - a[i - 1]) * cnt <= m)break;
			}
			if(sum + (a[i] - a[i - 1]) * cnt > m)break;
		}
		sum += (a[i] - a[i - 1]) * cnt;
		cnt++;
		maxn = max(maxn , cnt);
	}
	if(maxn == 1)cout << 0;
	else cout << maxn;
	return 0;
} 
