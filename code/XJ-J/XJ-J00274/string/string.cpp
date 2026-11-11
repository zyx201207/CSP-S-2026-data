#include <bits/stdc++.h> 
using namespace std;

#define sp ' '
#define endl '\n'

typedef long long ll;
typedef __int128 i128;

typedef vector <int> vi;

int n;
pair <int, string> a[214514];
ll ans, l, r, cnt;
char s[10];

int main() {
	freopen("string.in", "r", stdin),
	freopen("string.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	    scanf("%d%s", &a[i].first, s),
	    a[i].second = s,
	    cnt += a[i].first;
	
	for (int i = 1, j = n; i < j; ) {
	    int x = min(a[i].first, a[j].first);
		a[i].first -= x, a[j].first -= x;
		if (a[i].second != a[j].second)
		    ans += x;  
		
		
		if (a[i].first == 0)
		    ++i;
		if (a[j].first == 0)
		    --j;
	} 
	
	printf("%lld\n", ans);
	
	fclose(stdin),
	fclose(stdout);
	return 0;
}
