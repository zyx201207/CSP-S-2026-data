#include <bits/stdc++.h>

using namespace std;

long long n , qian , hou;
pair <long long , char> a[200005];
char q , h;
long long ans = 0;

int main() {
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++) {
		scanf("%lld %c" , &a[i].first , &a[i].second);
	}
	int i = 1 , j = n;
	qian = a[1].first , hou = a[n].first;
	q = a[1].second , h = a[n].second;
	while(i < j) {
		if(qian == 0) {
			i++;
			qian = a[i].first;
			q = a[i].second;
		}
		if(hou == 0) {
			j--;
			hou = a[j].first;
			h = a[j].second;
		}if(i >= j) break;
		int mi = min(qian , hou);
		if(q != h) {
			ans +=  mi;
		}
		qian -= mi;
		hou -= mi;
	}
	cout << ans;
	return 0;
}
