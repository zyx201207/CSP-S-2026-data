#include <bits/stdc++.h>
using namespace std;
const int MX = 2e5;
int n;
string s;
long long len = 0;
long long a[MX + 5];
char b[MX + 5];
int cnt = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i] >> b[i];
		for(long long j = 0;j < a[i];j++){
			s[j] = b[i];
		}
		len += a[i];
	}
	for(int i = 0;i < len;i++){
		if(s[i] != s[len - i]){
			cnt++;
			s[i] = s[len - i];
		}
	} 
	cout << cnt;
	return 0;
}
