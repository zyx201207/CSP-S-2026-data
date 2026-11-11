#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e5+10;
const int M = 3e5+10;
int n,m,a[N];
int anss[M];
int last[M] = {0},b[M] = {0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >>m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= m;j++){
			last[j] = b[j] = 0;
		}
		for (int j = i;j <= n;j++){
			if (last[a[j]]){
				for (int k = last[a[j]];k < j;k++){
					b[k] = 1;
					last[a[k]] = 0;
				}
			}
			last[a[j]] = j;
		}
		for (int j = i;j <= n;j++){
			int qwq = a[j];
			if (b[qwq]==0) anss[qwq]++;
		}
	}
	for (int i = 1;i <= m;i++){
		cout << anss[i] <<" ";
	}
	return 0;
}
