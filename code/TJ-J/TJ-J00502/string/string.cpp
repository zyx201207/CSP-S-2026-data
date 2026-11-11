#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s = "";
	long long sum = 0;
	while(n--){
		int x;
		char c;
		cin >> x >> c;
		for(int i = 1;i <= x;i++){
			s += c;
		}
		sum += x;
	}
	//aabbc
	//01234
	//sum = 5
	//sum / 2 = 2 
	long long ans = 0;
	for(int i = 0;i < sum/2;i++){
		if(s[i] != s[sum - 1 - i]) ans++;
	} 
	cout << ans;
	return 0;
}
