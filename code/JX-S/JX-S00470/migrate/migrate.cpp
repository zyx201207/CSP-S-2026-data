#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define fi first
#define se second
#define pb push_back

#define OI freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout)

using namespace std;

long long c;
long long n,d;
long long a[2000010];
int frt[2000010];

void solve(){
	int f[3010] = {0},g[3010] = {0},sum[3010] = {0};
	cin >> n >> d;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	
	for(int i = 1,j = 1;i <= n;i ++){
		while(a[i] - a[j] > d) j ++;
		frt[i] = j;
	//	cout << j << ' ';
	}
	//cout << '\n';
	
	int ans = 0;
	for(int i = 1;i <= n;i ++){
		memset(f,0,sizeof f);
		memset(g,0,sizeof g);
		memset(sum,0,sizeof g);
		g[i] = 1;
		sum[i] = 1;
		for(int j = i + 1;j <= n;j ++){
			int fir = max(frt[j],i);
			int k = fir;
			int l = k,r = j - 1,mid;
			while(l <= r){
				mid = (l + r) >> 1;
				if(f[mid] > f[fir]) r = mid - 1;
				else l = mid + 1,k = mid;
			}
		/*
			for(;k <= j - 1;k ++){
				if(k != fir && f[k] > f[k - 1]){
					break;
				}
				sum += g[k];
			}
			k --;
		*/
		//	cout << i << ' ' << j << ' ' << k << '\n';
			f[j] = f[k] + 1;
			g[j] = sum[k] - sum[fir - 1];
			sum[j] = sum[j - 1] + g[j];
		}
		
		for(int j = i;j <= n;j ++){
			if(g[j] == 2){
				//cout << "pair (" << i << ',' << j << ") is OK.\n";
				ans ++;
			}
		}
		/*
		cout << "f: ";
		for(int j = i;j <= n;j ++){
			cout << f[j] << ' ';
		}
		cout << '\n';
		
		cout << "g: ";
		for(int j = i;j <= n;j ++){
			cout << g[j] << ' ';
		}
		cout << '\n';
		*/
	}
	
	cout << ans << '\n';
}

void solveB(){
	cin >> n >> d;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	
	int dy = 0;
	
	for(int i = n;i >= 1;i --){
		if(a[i] - a[1] <= d){
			dy = i;
			break;
		}
	}
	
	if(dy == n || dy == 2){
		cout << 0 << '\n';
		return;
	}
	int ans = 0;
	for(int i = dy + 1;i <= n;i ++){
		if(a[i] - a[dy - 1] <= d && a[i] - a[dy - 2] > d) ans ++;
	}
	cout << ans << '\n';
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	OI;
	int T;
	cin >> c >> T;
	while(T --){
		if(c == 13 || c == 14) solveB();
		else solve();
	}
	return 0;
}

/*
 * O(n^3) hao xiang hen hao xie
 * xian xie zai shuo
 * wo hui O(n^2logn) le,nengpao n=5000 ma? /yiw
 * 
 * made,tiao bu chu lai
 * da yang li guo bu qu
 * 
 * tiao chu lai le
 * 
 * da le ge te shu xing zhi B
*/

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

/*
14 1
8 99
1 2 4 100 101 102 103 104
*/

