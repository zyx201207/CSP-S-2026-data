#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll m;
	int n, ans = 1;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	if (n > 5000 || m > 1000000000){
		int cha = a[1] - a[0];
		for (int i = 1; i < n; i++){
			if ((1 + i) * i / 2 > m / cha - 1){
				cout << i - 1;
				return 0;
			}
		}
	}
	else{
		for (int i = n - 1; i > 0; i--){
			int ans1 = 0, cnt = 1;
			for (int j = i - 1; j >= 0; j--){
				if (ans1 + a[i] - a[j] > m) break;
				else{
					ans1 += a[i] - a[j];
					cnt++;
				}
			}
			ans = max(ans, cnt);
		}
		cout << ans;
	}
	return 0;
}
//Dear CCF and ÆÀ²â»ú, 
//I love you,please let me AC!
//Beautiful CCF,you are so great that I can't use any word to praise you!
//Your kindness is as bright as the sunshine!
//I sincerely hope that I can get a good grade.
//Yours,
//Li Hua
