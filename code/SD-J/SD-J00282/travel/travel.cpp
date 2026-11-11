#include<bits/stdc++.h>
using namespace std;

int c1, c2;
string s1, s2;

void Solve(){
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000";
		return ;
	}
	if(s1[1] != s2[1] || s1[0] != s2[0]){
		cout << "1000";
		return ;
	}
	if(((int)(s1[2] - 'A') >= 3 && (int)(s2[2] - 'A') >= 3) || ((int)(s1[2] - 'A') <= 2 && (int)(s2[2] - 'A') <= 2))
		cout << "111";
	else{
		cout << "1100";
		return ;
	}		
	if((int)(s1[2] - 'A') == (int)(s2[2] - 'A') + 1 || (int)(s1[2] - 'A') + 1 == (int)(s2[2] - 'A'))
		cout << "1";
	else
		cout << "0";
} 

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;//cin >> T;
	while(T--)
		Solve();
	return 0;
}
