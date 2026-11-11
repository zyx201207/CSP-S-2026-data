#include <bits/stdc++.h>
#define ll long long
#define TIE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
struct chuan
{
	long long m;
	char c;
}g[2000010];
int n,l = 0,r,cnt = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	TIE
	cin >> n;
	r = n - 1;
	for (int i = 0; i < n; i++)
	{
		cin >> g[i].m >> g[i].c;
	}
	while (l < r)
	{
		while (g[l].m == 0) l++;
		while (g[r].m == 0) r--;
		if (g[l].c != g[r].c) cnt++;
		g[l].m--;
		g[r].m--;
	}
	if (n % 2 == 0) cnt -= 1;
	cout << cnt;
	return 0;
} 
