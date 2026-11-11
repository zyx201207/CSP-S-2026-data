#include<bits/stdc++.h>
using namespace std;
int s1[200010];
string s2[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int k = 0 ; k < n ; k++) {
		cin >> s1[k];
		string c;
		cin >> c;
		s2[k] = c;
	}
	int i = 0,j = n-1;
	long ans = 0;
	while (i < j) {
		if (s2[i] == s2[j]) {
			if (s1[i] > s1[j]) {
				s1[i] -= s1[j];
				s1[j] = 0;
				j--;
			} else if (s1[i] < s1[j]) {
				s1[j] -= s1[i];
				s1[i] = 0;
				i++;
			} else {
				s1[j] = 0;
				s1[i] = 0;
				j--;
				i++;
			}
		} else if (s2[i] != s2[j]) {
			if (s1[i] > s1[j]) {
				ans += s1[i] - s1[j];
				s1[i] -= s1[j];
				s1[j] = 0;
				j--;
			} else if (s1[i] < s1[j]) {
				ans += s1[j] - s1[i];
				s1[j] -= s1[i];
				s1[i] = 0;
				i++;
			} else {
				ans += s1[i];
				s1[i] = 0;
				s1[j] = 0;
				j--;
				i++;
			}
		}
	}
	cout << ans;
	return 0;
}
