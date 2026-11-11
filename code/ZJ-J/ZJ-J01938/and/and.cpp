#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[1000100];
vector<long long> s[40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		s[30].push_back(a[i]);
	}
	for(int i = 29;i >= 0;i--){
		long long cnt = 0;
		for(int j = 0;j < s[i + 1].size();j++){
			if(((s[i + 1][j] >> i) & 1) == 1){
				cnt++;
			}
		}
		if(cnt >= m){
			for(int j = 0;j < s[i + 1].size();j++){
				if(((s[i + 1][j] >> i) & 1) == 1){
					s[i].push_back(s[i + 1][j]);
				}
			}
		}else{
			for(int j = 0;j < s[i + 1].size();j++){
				s[i].push_back(s[i + 1][j]);
			}
		}
	}
	ans = s[0][0];
	for(int i = 1;i < m;i++){
		ans = (ans & s[0][i]);
	}
	cout << ans;
	return 0;
}
