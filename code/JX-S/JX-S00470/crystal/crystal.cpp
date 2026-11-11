#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define fi first
#define se second
#define pb push_back

#define OI freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout)

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m;
int a[500010];

bool check(int num){
	//cout << "Now check: " << num << "\n\n";
	deque <int> deq;
	int ans = 0,fans = INF;
	for(int i = 1;i <= num;i ++){
		deq.push_front(a[i]);
		ans += a[num] - a[i];
	}
	//cout << "1 to " << "num,cost" << ": " << ans << '\n';
	fans = ans;
	for(int i = num + 1;i <= n;i ++){
		ans -= (deq.front() - deq.back());
		deq.pop_back();
		if(!deq.empty()) ans += (a[i] - deq.front()) * num;
		deq.push_front(a[i]);
	//	cout << i - num << " to " << i << ",cost" << ": " << ans << '\n';
		fans = min(fans,ans);
	}
	//cout << '\n';
	return (fans <= m);
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	OI;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1,a + n + 1);
	
	int l = 1,r = n,mid;
	int ans = 0;
	while(l <= r){
		mid = (l + r) >> 1;
		if(check(mid)) l = mid + 1,ans = mid;
		else r = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}

//CSP-S 2026 JX
//start time: 22:30
//end time: 2:30

//do not forget to add freopen!

//stomach ache...
//nervous...

/* I can't spell Chinese...
 * da ping yin le
 * 
 * bu yao chi jiujiangxueyuan dui mian xiao chi jie de sheng hao he kao yu,
 * quan shi huai de
*/

/* zui hou yi wu le ma
 * wo zen me jiu chu san le
 * shi jian guo de hao kuai
*/

/*
10 10
-600 -500 -400 -300 -20 -10 0 10 15 100
*/

/*
now points:100 + [32,40] + 56 = [188,196]
now time: 6:00
*/


