#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200001], b[101] = {1}, s;
bool vis[200001];
int main(){
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	scanf ("%lld%lld" ,&n ,&m);
	memset(vis, true, sizeof(vis));
	for (int i = 1;i <= 31;i ++){
		b[i] = b[i - 1] * 2;
	}
	for (int i = 1;i <= n;i ++){
		scanf ("%lld" ,&a[i]);
	}
	for (int i = 30;i >= 0;i --){
		s = 0;
		for (int j = 1;j <= n;j ++){
			if (vis[j] && b[i] & a[j]){
				s ++;
			}
		}
		if (s < m){
			continue;
		}
		for (int j = 1;j <= n;j ++){
			if (!(b[i] & a[j])){
				vis[j] = false;
			}
		}
	}
	s = b[31] - 1;
	for (int i = 1;i <= n;i ++){
		if (vis[i]){
			s &= a[i];
		}
	}
	printf ("%lld" ,s);
	return 0;
}

