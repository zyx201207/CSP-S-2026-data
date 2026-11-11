#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1e6+10;
const int M = 1e9+10;
int n , a , rp;
char c , s[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while (n--){
		cin >> a >> c;
		for (int i = 1 ; i <= a ; i++){
			s[rp++] = c;
		}
	}
 	int cnt = 0;
	for (int i = 0 ; i < rp/2 ; i++){
		if (s[i] != s[rp-1-i]){
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
