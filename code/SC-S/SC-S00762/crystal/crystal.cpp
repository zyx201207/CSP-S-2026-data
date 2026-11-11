#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 5e5+5;
int n,lt,ans;
ll m, a[N],c[N],pre[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}sort(a + 1, a + n + 1);
	pre[1]=a[1];
	for (int i=2;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		c[i]=c[i-1]+(a[i]-a[i-1])*(i-1);
		int res = c[i]-(lt*a[i]-pre[lt]);
		while (res>m&&lt<i-1){
			lt++;
			res=c[i-1]+(a[i]-a[i-1])*(i-1)-(lt*a[i]-pre[lt]);
		}ans = max(ans,i-lt);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}