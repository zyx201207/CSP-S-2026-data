#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
constexpr int MAXN = 2e6+5;
int c, t, n, d, x[MAXN];
namespace naive{
	int la[MAXN], ra[MAXN], p1[MAXN], c1 = 0, p2[MAXN], c2 = 0;
	int solve(){
		int res = 0;
		int lp = 1, rp = 1;
		for(;x[rp]-x[lp] <= d && rp <= n;rp++);
		for(rp--;rp<=n;rp++){
			while(x[rp]-x[lp] > d)  lp++;
			la[rp] = lp;
		}
		lp = n, rp = n;
		for(;x[rp]-x[lp] <= d && lp >= 1;lp--);
		for(lp++;lp>=1;lp--){
			while(x[rp]-x[lp] > d)  rp--;
			ra[lp] = rp;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				c1 = c2 = 0;
				for(lp=i;lp && lp<j;lp=ra[lp])  p1[++c1] = lp;
				for(rp=j;rp && rp>i;rp=la[rp])  p2[++c2] = rp;
				p1[++c1] = j, p2[++c2] = i;
				if(c1 != c2)  continue;
				int flag = 0; 
				for(int i=1;i<=c1;i++){
					if(p1[i] != p2[c1-i+1]){
						flag++;
						if(flag >= 2)  break;
					}
				}
				//cout << i << " " << j << ":" << endl;
				//for(int i=1;i<=c1;i++)  cout << p1[i] << " " << p2[i] << endl; 
				if(flag == 1)  res++;
			}
		}
		return res;
	}
}
signed main(){
	cin.tie(nullptr); ios::sync_with_stdio(false);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for(;t;t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++)  cin >> x[i];
		cout << naive::solve() << endl;
	} 
	return 0;
}
