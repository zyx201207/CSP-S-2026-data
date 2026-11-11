#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000005;
const int M = 5005;
int n,m,a[N];
bool check(int s){
//	cout << s << "大检测\n";
	int cnt = m,lst = 0;
	for(int i = 1;i <= n;i++){
		if(i <= s){
			cnt -= (a[i]-lst)*(i-1);
			lst = a[i];
			if(i == s && cnt >= 0)
				return true;
		}
		else{
			cnt -= (a[i]-lst)*(s-1);
			cnt += (lst-a[i-s+1]);
			lst = a[i];
			if(cnt >= 0)
				return true;
		}
//		cout << i << "是gay:" << lst << ' ' << cnt << '\n';
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	system("fc crystal.out crystal4.ans");
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	int l=0,r=n,ans;
	while(l <= r){
		int mid = (l+r)>>1;
		if(check(mid)){
			l = mid+1;
			ans = mid;
		}
		else
			r = mid-1;
	}
	cout << ans << '\n';
	return 0;
}
/*
3 1
1 2 3
CCF Just_do_it.png
luoguID:Flynewcat
尽管我无法证明它的对错，但我坚信它是对的！ 
*/
