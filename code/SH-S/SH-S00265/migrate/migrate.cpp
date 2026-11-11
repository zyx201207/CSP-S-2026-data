#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 10;
const long long INF = 1e18;

long long ans = 0;
long long dis[MAXN];
long long cnt[MAXN];
long long isl[MAXN];
long long c, t, n, d;

void solve1(){
	for(; t; t --){
		
		scanf("%lld%lld", &n, &d);
		for(int i = 0; i < min(n, 2ll); i ++) scanf("%lld", &isl[i]);
		string s;
		while((s = getchar()) != "\n");
		
		if(n == 1){
			printf("0\n");
			continue;
		}
		
		long long x = isl[1] - isl[0];
		
		if(2 * x > d || x == 0){
			printf("0\n");
			continue;
		}
		long long y = 2 * (d / x) - 1;
		
		printf("%d\n", max(0ll, n - y));
		
	}
	
	return ;
}


void solve2(){
	for(; t; t --){
		
		scanf("%lld%lld", &n, &d);
		for(int i = 0; i < n; i ++) scanf("%lld", &isl[i]);
		
		if(n <= 3){
			printf("0\n");
			continue;
		}
		
		int l = 0, r = n - 1;
		while(l < r){
			int mid = (l + r) / 2;
			if(isl[mid] > (isl[0] + isl[n - 1]) / 2){
				r = mid;
			}else if(isl[mid] == (isl[0] + isl[n - 1]) / 2){
				l = mid; r = mid;
			}else{
				l = mid + 1;
			}
		}
		
		if(isl[l] - isl[0] > d) l--;
		if(isl[n - 1] - isl[l] > d) l++;
		
		if(l == n - 1 || l == 0){
			printf("0\n");
			continue;
		}
		
		int a = l;
		
		l = 0, r = n - 1;
		if(isl[a - 1] + d < isl[n - 1])
		while(isl[l] < isl[r]){
			int mid = (l + r) / 2;
			if(isl[mid] > isl[a - 1] + d){
				r = mid;
			}else{
				l = mid + 1;
			}
		}
		else{
			r = n;
		}
		
		int b = n - r;
		
		l = 0, r = n - 1;
		if(isl[a + 1] - d > isl[0])
		while(isl[l] < isl[r]){
			int mid = (l + r) / 2;
			if(isl[mid] > isl[a + 1] - d){
				r = mid;
			}else{
				l = mid + 1;
			}
		}
		else{
			l = -1;
		}
		
		int e = l + 1;
		
		
		l = 0, r = n - 1;
		if(a > 2 && isl[a - 2] + d <= isl[n - 1]){
			
		while(isl[l] < isl[r]){
			int mid = (l + r) / 2;
			if(isl[mid] >= isl[a - 2] + d){
				r = mid;
			}else{
				l = mid + 1;
			}
		}
		if(isl[l] >= isl[a + 2] - d) r --;
		}
		else{
			r = n;
		}
		
		int x = n - r;
		
		l = 0, r = n - 1;
		if(a < n - 3 && isl[a + 2] - d >= isl[0]){
			
		while(isl[l] < isl[r]){
			int mid = (l + r) / 2;
			if(isl[mid] >= isl[a + 2] - d){
				r = mid;
			}else{
				l = mid + 1;
			}
		}
		if(isl[l] >= isl[a + 2] - d) l --;
		}
		else{
			l = -1;
		}
		
		
		int y = l + 1;
		
		ans = max(0, x - b) * e + max(0, y - e) * b;
		
		printf("%d\n", max(0ll, ans));
		
	}
	
	return ;
}



int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	
	if(c == 11 || c == 12){
		solve1();
		return 0;
	}
	
	if(c == 13 || c == 14){
		solve2();
		return 0;
	}
	
	
	for(; t; t --){
		
		ans = 0;
		
		scanf("%lld%lld", &n, &d);
		for(int i = 0; i < n; i ++) scanf("%lld", &isl[i]);
		
		for(int i = 0; i < n; i ++){
			dis[i] = 0;cnt[i] = 1;
			
			for(int j = i + 1; j < n; j ++){
				dis[j] = INF; cnt[j] = 0;
				bool specialjudge = true;
				for(int k = j - 1; k >= i; k --){
					if(isl[j] - isl[k] <= d){
						if(cnt[k] < 3){
							specialjudge = false;
						}	
						if(dis[j] == dis[k] + 1) cnt[j] += cnt[k];
						if(dis[j] > dis[k] + 1) cnt[j] = cnt[k];
						dis[j] = min(dis[j], dis[k] + 1);
					}else{
						break;
					}
				}
				if(cnt[j] == 0) break;
				if(specialjudge) break;
//				printf("from %d to %d have %d road with %d\n", i, j, cnt[j], dis[j]);
				if(cnt[j] == 2){
					ans ++;
				} 
			}
		}
		
		cout << ans << "\n";
	}
	
	
	return 0;
}
