#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 32;
int c, t;
int n, d;
int x[N];
int cntl;
int minl;
void dfs(int cur, int t, int len){
	if(len > minl)	return;
	if(cur == t){
		if(len < minl){
			minl = len;
			cntl = 1;
		}
		else if(len == minl){
			++cntl;
		}
		return;
	}	
	for(int i = cur + 1; i <= t; ++i){
		if(x[i] - x[cur] <= d){
			dfs(i, t, len + 1);
		}
	}
}
int get_minl(int cur, int t, int len){
	if(cur >= t)	return len;
	int l = cur + 1;
	int r = t;
	int mid, ans;
	while(l <= r){
		mid = (l + r) >> 1;
		if(x[mid] - x[cur] <= d){
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
	}
	return get_minl(ans, t, len + 1);
}
bool check_A(){
	int ff = x[2] - x[1];
	for(int i = 2; i <= n - 1; ++i){
		if(x[i + 1] - x[i] != ff)	return false;
	}
	return true;
}
void solveA(){
	int ANS = 0;
	int ff = x[2] - x[1];
	if(ff > d){
		cout << 0 << "\n";
		return;
	}
	int t = d / ff;
	d = ff * t;
	for(int len = 1; len <= n - 1; ++len){
		int r = len % t;
		if(r != 0 &&t + r == len && t == 2){
			ANS += (n - len);
		}
	}
	cout << ANS << "\n";
	return;
}
int ptr;
bool check_B(){
	int l = x[n] - d;
	int r = x[1] + d;
	for(int i = 1; i <= n; ++i){
		if(x[i] >= l && x[i] <= r){
			ptr = i;
			return true;
		}
	}
	return false;
}
void solveB(){
	int fnl = 0;
	for(int i = 1; i <= n; ++i){
		int cur = x[i];
		int l = 1;
		int r = n;
		int ans, mid;
		while(l <= r){//求最大的满足x[q] <= x[l] + d
			//如果q = ptr, 那么需要再回退一个，判断从这个点出发直达的点是哪些 
			mid = (l + r) >> 1;
			if(x[mid] - x[i] <= d){
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		int q = ans;
		if(q == ptr)	--q;
		//if(q != ptr){
			int lft = x[q - 1] + d + 1;
			int rgt = x[q] + d;
			l = 1;
			r = n;
			while(l <= r){
				mid = (l + r) >> 1;
				if(x[mid] >= lft){
					r = mid - 1;
					ans = mid;
				}
				else l = mid + 1;
			}
			int anslft = ans;
			l = 1;
			r = n;
			while(l <= r){
				mid = (l + r) >> 1;
				if(x[mid] <= rgt){
					l = mid + 1;
					ans = mid;
				}
				else r = mid - 1;
			}
			int ansrgt = ans;
			while(x[ansrgt]> rgt)	--ansrgt;
			while(x[anslft]< lft)	++anslft;
			if(anslft > ansrgt)	continue; 
			fnl += (ansrgt - anslft + 1);
		//}
	}
	cout << fnl << "\n";
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		int ans = 0;
		for(int i = 1; i <= n; ++i)	cin >> x[i];
		if(check_A() && n > 5000)	solveA();
		else if(check_B() && n > 5000)	solveB();
		else{ 
			for(int i = 1; i <= n; ++i){
				for(int j = i + 1; j <= n; ++j){
					cntl = 0;
					minl = get_minl(i, j, 0);
					dfs(i, j, 0);
					if(cntl == 2)	++ans;
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
