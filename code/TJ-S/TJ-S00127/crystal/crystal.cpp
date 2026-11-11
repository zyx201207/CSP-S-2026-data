#include <bits/stdc++.h>
using namespace std;
const int Max = 5e5 + 10;
int n;
long long m,a[Max],z[Max],anss;
vector<long long> s[Max];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for (int i = 2;i <= n;i++){
		z[i] = a[i] - a[i - 1];
	}
	for (int i = 1;i <= n;i++){
		long long x = 0;
		for (int j = i;j >= 1;j--){
			s[i].push_back(x);
			x += z[j];
		}
	}
	for (int i = 1;i <= n;i++){
		long long cnt = 0;
		long long num = 0;
		for (int j = 0;j < i;j++){
			cnt += s[i][j];
			if (cnt > m){
				break;
			}else{
				num++;
			}
		}
		anss = max(anss,num);
	}
	cout << anss;
	return 0;
}
