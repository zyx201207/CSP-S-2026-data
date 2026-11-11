#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,s[1000010],t,c,ex[1000010];
int solve1(){
	memset(ex,0,sizeof(ex));
	int num = 0;
	for(int a = 1;a <= n - 3;a++){
		if(s[a + 2] - s[a] <= m && s[a + 3] - s[a + 1] <= m && s[a + 3] - s[a] > m){
			num++;
			ex[num] = a;
		}
	}
	int ans = 0;
	ex[0] = -0x3f3f3f3f3f3f3f3f;
	ex[num + 1] = 0x3f3f3f3f3f3f3f3f;
	for(int a = 1;a <= num;a++){
		int lmax = 1,rmax = 1,l1 = 0,l2 = 0,r1 = 0,r2 = 0,l = ex[a],r = ex[a] + 3;
		l1 = s[ex[a] + 1] - s[ex[a]];
		l2 = s[ex[a] + 2] - s[ex[a]];
		r1 = s[ex[a] + 3] - s[ex[a] + 2];
		r2 = s[ex[a] + 3] - s[ex[a] + 1];
		while(l > 1){
			if(l1 + s[l] - s[l - 1] <= m && l2 + s[l] - s[l - 1] > m) break;
			if(s[l] - s[l - 1] > m) break;
			if(l - 1 <= ex[a - 1]) break;
			if(l1 + s[l] - s[l - 1] <= m && l2 + s[l] - s[l - 1] <= m){
				l1 += s[l] - s[l - 1];
				l2 += s[l] - s[l - 1];
			}
			else{
				l1 = 0;
				l2 = 0;
			}
			lmax++;
			l--;
		}
		while(r < n){
			if(r1 + s[r + 1] - s[r] <= m && r2 + s[r + 1] - s[r] > m) break;
			if(s[r + 1] - s[r] > m) break;
			if(r + 1 >= ex[a + 1] + 3) break;
			if(r1 + s[r + 1] - s[r] <= m && r2 + s[r + 1] - s[r] <= m){
				r1 += s[r + 1] - s[r];
				r2 += s[r + 1] - s[r];
			}
			else{
				r1 = 0;
				r2 = 0;
			}
			rmax++;
			r++;
		}
		ans += lmax * rmax;
	}
	return(ans);
}
int solve2(){
	memset(ex,0,sizeof(ex));
	int num = 0;
	for(int a = 1;a <= n - 5;a++){
		if(s[a + 3] - s[a] <= m && s[a + 5] - s[a + 2] <= m && s[a + 5] - s[a] > m){
			num++;
			ex[num] = a;
		}
	}
	int ans = 0;
	ex[0] = -0x3f3f3f3f3f3f3f3f;
	ex[num + 1] = 0x3f3f3f3f3f3f3f3f;
	for(int a = 1;a <= num;a++){
		int lmax = 1,rmax = 1,l1 = 0,l2 = 0,r1 = 0,r2 = 0,l = ex[a],r = ex[a] + 5;
		l1 = s[ex[a] + 2] - s[ex[a]];
		l2 = s[ex[a] + 3] - s[ex[a]];
		r1 = s[ex[a] + 5] - s[ex[a] + 3];
		r2 = s[ex[a] + 5] - s[ex[a] + 2];
		while(l > 1){
			if(l1 + s[l] - s[l - 1] <= m && l2 + s[l] - s[l - 1] > m) break;
			if(s[l] - s[l - 1] > m) break;
			if(l - 1 <= ex[a - 1]) break;
			if(l1 + s[l] - s[l - 1] <= m && l2 + s[l] - s[l - 1] <= m){
				l1 += s[l] - s[l - 1];
				l2 += s[l] - s[l - 1];
			}
			else{
				l1 = 0;
				l2 = 0;
			}
			lmax++;
			l--;
		}
		while(r < n){
			if(r1 + s[r + 1] - s[r] <= m && r2 + s[r + 1] - s[r] > m) break;
			if(s[r + 1] - s[r] > m) break;
			if(r + 1 >= ex[a + 1] + 5) break;
			if(r1 + s[r + 1] - s[r] <= m && r2 + s[r + 1] - s[r] <= m){
				r1 += s[r + 1] - s[r];
				r2 += s[r + 1] - s[r];
			}
			else{
				r1 = 0;
				r2 = 0;
			}
			rmax++;
			r++;
		}
		ans += lmax * rmax;
	}
	return(ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> m;
		for(int a = 1;a <= n;a++) cin >> s[a];
		cout << solve1() + solve2() << endl;
	}
	return(0);
}
