#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string .out","w",stdout);
	int n,cnt = 0;
	cin >> n;
	string s,a,c;
	for(int i=0;i<=n + 1;i++){
		cin >> s[i];
		for(int i=1;i<=s[i];i++){
			a[i] = s[2];
		}
	}
	for(int i=n + 1;i>=0;i--){
		if(c[i] == a[i]){
			cnt = cnt;
		}
		else{
			cnt++;
		}
	}
	cout << cnt / 2;
}
