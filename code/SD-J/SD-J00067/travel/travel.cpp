#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pb push_back
#define pii pair<int, int>
#define pque priority_queue
#define umap unordered_map

using namespace std;

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch - '0');
		ch = getchar();
	}
	return x * f;
}

void write(int x)
{
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar((char)(x % 10 + '0'));
}

signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) putchar('1');
	else putchar('0');
	string t1 = s1.substr(0, 2), t2 = s2.substr(0, 2);
	if(c1 == c2 && t1 == t2) putchar('1');
	else putchar('0');
	bool j1 = (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'), 
		j2 = (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C');
	if(c1 == c2 && t1 == t2 && j1 == j2) putchar('1');
	else putchar('0');
	if(c1 == c2 && (t1 == t2) && (j1 == j2) && (abs((int)s1[2] - (int)s2[2]) == 1 || (s1[2] == 'D' && s2[2] == 'F' || 
		s2[2] == 'D' && s1[2] == 'F'))) 
		putchar('1');
	else putchar('0');
	
	return 0;
}

