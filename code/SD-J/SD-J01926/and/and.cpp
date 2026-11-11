#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
string a[N] , b[N];
int shuzu[N];
int  c[N] , ji[N];
signed main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n , m;
	cin >> n >> m;
	int mx = 0;
	for(int i = 1; i <= n; i ++){
		int x;
		cin >> x;
		shuzu[i] = x;
		string s = "";
		while(x){ 
			s += (x % 2 + '0');
			x /= 2;
		} 
		reverse(s.begin() , s.end());
		a[i] = s;
		a[i] = " " + a[i];
		int l = s.size();
		mx = max(mx , l);
	} 
	for(int i = 1; i <= n; i ++){
		int id = 1;
		for(int j = mx - a[i].size() + 1; j <= mx; j ++){
			b[i][j] = a[i][id];
			id ++;			
		}
	} 
	int first1 = 0;
	int tm = 0 , id = 0;
	for(int i = 1; i <= mx; i ++){
		int cnt = 0;
		for(int j = 1; j <= n; j ++){
			if(b[j][i])
				cnt ++;
		}
		if(cnt < m)
			continue;
		first1 ++;
		if(first1 == 1){
			for(int j = 1; j <= n; j ++)
				if(b[j][i])
					id ++ , c[id] = j , ji[j] = 1;
		}
		else{
			int last = ji[c[1]];
			for(int j = 1; j <= id; j ++){
				if(b[c[j]][i] == 1)
					ji[c[j]] ++;
			} 
			int cntcnt = 0;
			for(int j = 1; j <= id; j ++){
				if(ji[c[j]] != last)
					cntcnt ++;
			}
			if(cntcnt <= m)
				continue;
			for(int j = 1; j <= id; j ++){
				if(b[c[j]][i] == 1 && b[c[j]][i] == last + 1)
					ji[c[j]] --;
			} 			
		}
	}
	int mxx = 0;
	for(int i = 1; i <= n; i ++)
		mxx = max(mxx , ji[i]);
	int k = 0;
	int ans = 0;
	for(int i = 1; i <= n; i ++){
		if(ji[i] == mxx && k == 1)
			k ++ , ans = shuzu[i];
		if(ji[i] == mxx && k <= m && k != 1)
			k ++ , ans = (ans & shuzu[i]);
	} 
	cout <<ans;

	return 0;
}

