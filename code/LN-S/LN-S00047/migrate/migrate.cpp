#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = int;

using i128 = __int128;
using u128 = unsigned __int128;

#ifdef ZYX2012_DUIPAI
mt19937_64 mrand(random_device{}());
i64 rnd(i64 l,i64 r){
	return mrand() % (r - l + 1) + l;
}
#endif

void solve(){
	int n;
	i64 d;
	cin >> n >> d;

	vector<i64> x(n + 1);
	vector<int> prv(n + 2,1),nxt(n + 2,n);

	for (int i = 1;i <= n;i++){
		cin >> x[i];
		prv[i] = prv[i - 1];
		for (;x[i] - x[prv[i]] > d;prv[i]++);
	}

	nxt[n] = n;

	for (int i = n;i;i--){
		nxt[i] = nxt[i + 1];
		for (;x[nxt[i]] - x[i] > d;nxt[i]--);
	}

	vector<i64> cntl(n + 1),cntl2(n + 1),cntr(n + 1);

	for (int i = 1;i < n;i++){
		if (nxt[i] != nxt[i - 1]){
			cntl[nxt[i]] += cntl[i];
			if (nxt[i - 1] + 1 < nxt[i]) cntl2[nxt[i]] += cntl[i];
		}
		cntl[nxt[i]]++,cntl2[nxt[i]]++;
	}

	for (int i = n;i > 1;i--){
		if (prv[i] != prv[i + 1]){
			cntr[prv[i]] += cntr[i] + 1;
		}else
			cntr[prv[i]]++;
	}

	i64 ans = 0;

//	for (int i = 1;i <= n;i++) cout << cntl[i] << ' ' << cntr[i] << '\n';

	for (int i = 3;i < n;i++){
		if (i < nxt[i - 1])
			/*cout << i << " t1 " << cntl2[i] << ' ' << nxt[i - 1] - max(nxt[i - 2],i) << '\n',/**/ans += cntl2[i] * (nxt[i - 1] - max(nxt[i - 2],i));
		if (nxt[i] == nxt[i - 1]&&nxt[i] != nxt[i - 2])
			/*cout << i << " t2 " << cntl2[i] << ' ' << cntr[nxt[i]] << '\n',/**/ans += cntl2[i] * cntr[nxt[i]];
	}

	cout << ans << '\n';
}

int main (){
	//如果标算太难请坚定信念，不如回头再看一眼题面，以那暴力模拟向正解吊唁
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	int c,T;
	cin >> c >> T;

	for (;T--;solve());
}