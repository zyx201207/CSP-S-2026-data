#include <bits/stdc++.h> 
using namespace std;

#define sp ' '
#define endl '\n'

typedef long long ll;
typedef __int128 i128;

typedef vector <int> vi;

int n, m, dis[214514];
ll a[214514], pow2[32], ans;

int main() {
	freopen("and.in", "r", stdin),
	freopen("and.out", "w", stdout);
    
    for (int i = 0; i < 32; i++)
        pow2[i] = 1LL << i;
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	    scanf("%lld", &a[i]);
	 
	for (int i = 31; i >= 0; i--) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) 
		    if (dis[j] == 0)
			    if (a[j] & pow2[i])
		            ++cnt;
		
		if (cnt >= m) {
			for (int j = 1; j <= n; j++) 
				if (dis[j] == 0)
				    if (!(a[j] & pow2[i]))
				        dis[j] = 1;
			
			ans += pow2[i];
		}
	} 
	
	printf("%lld\n", ans);
	
	fclose(stdin),
	fclose(stdout);
	return 0;
}

/*
4 2
3 15 12 12

0010 
1111
1100
1100
*/
