#include<bits/stdc++.h>
using namespace std;
long long int n, m, cnt[500010], a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
	cin >> a;
	cnt[a] ++;
	}
	for (int i =1 ;i <= m; i++)cout << cnt[i] << ' ';
	return 0;
}