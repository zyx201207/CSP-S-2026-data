#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n,m,head,tail,a[N],cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	tail = n;
	for (int i = 1;i <= n;i++) {
		for (int j = i;j <= n;j++) {
			cnt[a[j]]++;
		}
	} 
	for (int i = 1;i <= m;i++) {
		cout << cnt[i] << " ";
	}
	return 0;
	//orz orz orz
	//freopen(xiele
}
