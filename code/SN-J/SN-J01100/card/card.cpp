#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500005;
const int M = 5005;
int cnt[N],n,m,a[N],lst[N],nxt[N],ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	system("fc card.out card6.ans");
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = n;i >= 1;i--){
		if(lst[a[i]] == 0)
			lst[a[i]] = i;
	}
	for(int i = n;i >= 1;i--){
		if(i == n){
			lst[a[i]] = n;
			nxt[i] = n;
			cnt[i]++;
			continue;
		}
		if(lst[a[i]] == i){
			int p = lst[a[i+1]];
			cnt[i]++;
			nxt[i] = p;
		}
		else{
			int p = lst[a[i]];
			cnt[i]++;
			nxt[i] = p;
			int u = i;
		}
//		cout << nxt[i] << '\n';
	}
	for(int i = 1;i <= n;i++){
		if(i != n)
			cnt[nxt[i]] += cnt[i];
		if(lst[a[i]] == i)
			ans[a[i]] = cnt[i];
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i];
		if(i != m)
			cout << ' ';
	}
	return 0;
}
//|d|b|a|c|b|a|d|c|a|d|b|d|
/*
4 3
1 2 1 3
CCF Just_do_it.png
Flynewcat
尽管我无法证明它的对错，但我坚信它是对的！ 
*/
