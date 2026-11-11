#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,cnt = 0;
	int a[1001];
	char zm[1001];
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i] >> zm[i];
		cnt += a[i];
	}
	
	for(int i = 1;i <= cnt;i++){
		for(int j = 1;j <= a[i];j++){
			hfc[j] = zm[i];
		}
	}
	
	return 0;
}