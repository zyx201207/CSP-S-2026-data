#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
stack<int> s;
bool f[500005];
int cnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		for (int k = 1; k <= m; k++) f[k] = false;
		for (int j = i; j <= n; j++){
			if (f[a[j]] == false){
			    s.push(a[j]);
			    f[a[j]] = true;
		    }else if (f[a[j]] == true){
		        while (s.top() != a[j]){
					s.pop();
					if (s.top() == a[j]) break;
			    }
		    }
		}
		while (!s.empty()){
			cnt[s.top()]++;
			s.pop();
		}
	}
	for (int i = 1; i <= m; i++){
		cout << cnt[i] << " ";
	}
	return 0;
}
