#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define int long long
using ll = long long;
int n, m;
int a[200005];
int ans = 0;
void dfs(int x, int l,int res){
	if(res <= ans) return;
	if(x == m+1){
		ans = max(ans, res);
	}
	rep(i, l+1, n){
		int tmp = res & a[i];
		dfs(x+1, i, tmp);
	}
}
int ma = 0, k = 1;
bool A = 1;
int cnt[33];
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	srand(time(0));
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	rep(i, 1, n){
		cin>>a[i];
		ma = max(ma, a[i]);
		int tmp = a[i], times = 0;
		if(tmp == 0) cnt[0]++;
		while(tmp){
			tmp >>= 1;
			times++;
			if(tmp << times != a[i] && tmp){
				A = 0;
			} 
			if(tmp == 0) cnt[times-1]++;
		}
	}
	if(n <= 20){
		dfs(1, 0, (1ll<<31)-1);
		cout<<ans;
		return 0;
	}
	if(m == 1){
		int maxx = 0;
		rep(i, 1, n){
			maxx = max(maxx, a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(n == m){
		int res = (1ll<<31)-1;
		rep(i, 1, n){
			res &= a[i];
		}
		cout<<res;
		return 0;
	}
	if(m == 2){
		for(int j=30;j>=0;j--){
			vector<int> v;
			rep(i, 1, n){
				if((a[i] >> j) & 1){
					v.push_back(a[i]);
				}
			}
			if(v.size() >= 2){
				int res = 0;
				for(int i=0;i<v.size();i++){
					for(int j=i+1;j<v.size();j++){
						res = max(res, a[i] & a[j]);
					}
				}
				cout<<res;
				return 0;
			}
			v.clear();
		}
		cout<<0;
		return 0;
	}
	if(n == m-1){
		int minn = 1ll<<31;
		rep(i, 1, n){
			minn = min(minn, a[i]);
		}
		bool Skip = 1;
		int res = (1ll<<31)-1;
		rep(i, 1, n){
			if(Skip && a[i] == minn){
				Skip = 0;
				continue;
			}
			res &= a[i];
		}
		cout<<res;
		return 0;
	}
	if(A){
		for(int i=30;i>=0;i--){
			if(cnt[i] >= m){
				cout<<1ll<<i;
				return 0;
			}
		}
		cout<<0;
		return 0;
	}
	int res = (1ll << 31)-1;
	for(int i=n;i>n-m;i--){
		res &= a[i];
	}
	cout<<res;
	return 0;
}
//fc.exe and.out and1.ans

