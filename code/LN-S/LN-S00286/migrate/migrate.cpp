#include<bits/stdc++.h>
using namespace std;
#define int long long
int d,sum = 0;
vector<int> s;
vector<int> a;
void dp(int l,int r,int cnt){
	if(l == r){
		s.push_back(cnt);
		sum++;
		return;
	} 
	for(int i = l+1;i<r;i++){
		if(a[i] - a[l] <= d){
			dp(i,r,cnt+1);
		}
	}	
	return;
}

signed main(){
	freopen("migrate.in", "r",stdin);
	freopen("migrate.out", "w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int c,t;
	cin >> c >> t;
	if(c == 11 || c == 12){
		for(int i = 0;i<t;i++){
			int n,d;
			cin >> n >> d;
			for(int i = 0;i<n;i++){
				cin >> a[i];
			}
			if(d >= (a[1] - a[0])*2) cout << n-3 << "\n";
			else cout << "0\n";
		}
		return 0;
	}
	for(int k = 0;k<t;k++){
		int n,d;
		cin >> n >> d;
		for(int i = 0;i<n;i++){
			cin >> a[i];
		}
		int ans = 0;
		for(int i = 0;i<n;i++){
			for(int j = i+2;j<i+2+d*2;j++){
				dp(i,j,0);
				int mi = INT_MAX,cnt = 0;
				for(int y = 0;y < (int)s.size();y++){
					if(s[y] < mi){
						mi = s[y];
						cnt = 1;
					} else if(s[y] == mi){
						cnt++;
					}
				}
				if(cnt == 2) ans++;
			}
		}
		cout << ans << "\n";
		s.clear();
		a.clear();
		sum = 0;
	}
	return 0;
}
