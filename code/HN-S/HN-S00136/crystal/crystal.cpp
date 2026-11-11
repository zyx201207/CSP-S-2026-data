#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pi pair<int,int>
#define mini pi,vector<pi>,greater<pi>
#define fs first
#define se second
#define P_Q priority_queue
using namespace std;
const int N = 5e5 + 5, inf = 0x3f3f3f3f3f3f3f3f;

int n, m;
int a[N];
int s[N];

/*
1 2 4 8  9
1 3 7 15 24

 (i - mid) * a[i] - (s[i - 1] - s[mid - 1])
*/

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin); freopen("crystal.out","w",stdout);

	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = -inf;
	
	for(int i = 1;i <= n;i++)
		s[i] = s[i - 1] + a[i];
	
	for(int i = 1;i <= n;i++){
		
		if(n * n <= 1e7){
			int cnt = 0, sum = 0;
			for(int j = i - 1;j >= 1;j--){
				if(sum + a[i] - a[j] <= m) sum += a[i] - a[j], cnt++;
				else break;
			}
			ans = max(ans, cnt + 1);
		}else{
			int l = 0, r = i;
			while(l < r){
				int mid = (r + l) >> 1;
				if((i - mid) * a[i] - (s[i - 1] - s[mid - 1]) <= m) r = mid;
				else l = mid + 1;
			}
			ans = max(ans, i - r + 1);
		}
	}
	
	cout << ans;

	return 0;
}

