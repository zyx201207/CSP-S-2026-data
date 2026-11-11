#include<bits/stdc++.h>

using namespace std;
long long n,a[200010],num;
char c[200010];
string s;
int main(){
	freopen("r","string.in",stdin);
	freopen("w","string.out",stdout);
	cin >> n;
	for(long long i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	s = " ";
	for(long long i = 1; i <= n; i++){
		for(long long j = 1; j <= a[i]; j++){
			s += c[i];
		}
	}
	long long l = s.length() - 1;
	for(long long i = 1; i <= l / 2; i++){
		if(s[i] != s[l + 1 - i]){
			num++;
		}
	}
	cout << num << endl;
	return 0;
}
