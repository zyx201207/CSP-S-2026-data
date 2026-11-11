#include <bits/stdc++.h>
using namespace std;
int n,m;
string s,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> n >> s;
	cin >> m >> c;
	if(n == m){
		cout << 1;
	}
	else{
		for(int i = 1;i <= 4;i++){
			cout << 0;
		}
		return 0;
	}
	if(s[0] == c[0] && s[1] == c[1]){
		cout << 1;
	}
	else{
		for(int i = 1;i <= 3;i++){
			cout << 0;
		}
		return 0;
	}
	if((s[2] <= 'C' && c[2] <= 'C') || (s[2] >= 'D' && c[2] >= 'D')){
		cout << 1;
	}
	else{
		for(int i = 1;i <= 2;i++){
			cout << 0;
		}
		return 0;
	}
	bool flag = 0;
	if(s[2] == 'D' && c[2] == 'F') flag = 1;
	if(s[2] == 'F' && c[2] == 'D') flag = 1;
	if(s[2] == 'A' && c[2] == 'B') flag = 1;
	if(s[2] == 'B' && c[2] == 'C') flag = 1;
	if(flag == 1) cout << 1;
	else cout << 0;
	return 0;
}
