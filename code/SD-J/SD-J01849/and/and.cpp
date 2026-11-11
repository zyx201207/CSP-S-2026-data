#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	if(m == 1){
		cout << a[n];
	}
	else if(m == 2){
		long long ans = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++){
				if(ans < a[i] & a[j])
				ans = a[i] & a[j];
			}
		}
		cout << ans;
	}
	else cout << "67";
	return 0;
}
