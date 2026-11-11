#include <bits/stdc++.h> 
using namespace std;

#define sp ' '
#define endl '\n'

typedef long long ll;
typedef __int128 i128;

typedef vector <int> vi;

int n, m, a[514514], l[514514], ans[514514];

bool special1() {
	bool ok = 1;
	for (int i = 2; i <= n; i++)
	    if (a[i - 1] > a[i])
	        ok = 0;
	return ok;
}

int main() {
	freopen("card.in", "r", stdin),
	freopen("card.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	    scanf("%d", &a[i]);
	
	if (special1())
		for (int i = 1; i <= n; i++)
		    ans[a[i]] = i;
	else {
		for (int i = n; i; i--)
			if (l[a[i]] == 0)
			    l[a[i]] = i;
		
		for (int i = 1; i <= n; i++) 
			for (int j = i; j <= n; j++) 
				++ans[a[j]],
				j = l[a[j]];
	}
	
	for (int i = 1; i <= m; i++)
	    printf("%d ", ans[i]);
	printf("\n");
	
	fclose(stdin),
	fclose(stdout);
	return 0;
}
