#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, a[500001], c[500001], pos, cnt[300001];

signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	    cin >> a[i];
	for (int i = 1; i <= n; i++){
		pos = 0;
		for (int j = i; j <= n; j++){
			bool ok = true;
			for (int k = 1; k <= pos; k++)
			    if (c[k] == a[j]){
			    	pos = k;
			    	c[pos] = a[j];
			    	ok = false;
			    	break;
				}
			if (ok)
			    c[++pos] = a[j];
		}
		for (int j = 1; j <= pos; j++)
		    cnt[c[j]]++;
	}
	for (int i = 1; i <= m; i++)
	    cout << cnt[i] << " ";
	cout << endl;
}//只会暴力，估分24 
//哇可以耍起了耶，耍起 耍起 耍起 耍起 耍起 耍起 耍起 耍起 耍起 耍起 耍起 耍起 耍起 耍起 耍起 耍起 耍起 耍起 耍起 耍起 耍起 耍起 耍起 耍起
//求你了CCF，give me1=  
