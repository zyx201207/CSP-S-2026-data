#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	int count = 0;
	int a[100001];
	cin >> n >> m;
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort (a, a + n);
	for (int i =1;i < n;i ++){
		for (int j = 1;j <= m;j ++){
			while (m >= 0){
				if (a[j] > a[i]){
					m -= 1;
					count += 1;
					a[i] = max(a[i-1],a[j]);
				}
			}
		}
	} 
	cout << count;
	return 0;
}

