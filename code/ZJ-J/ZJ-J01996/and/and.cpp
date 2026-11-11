#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[200005];
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	int maxn = -1;
	for (int i = 1;i < n-1;i++){
		for (int j = i + 1;j < n;j++){
			for (int k = j + 1;k <= n;k++){
				maxn = max(maxn,a[i] & a[j] & a[k]);
			}
		}
	}
	cout << maxn;
	return 0;		
}