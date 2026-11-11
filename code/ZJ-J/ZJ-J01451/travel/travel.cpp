#include<bits/stdc++.h>
#define ll long long
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl "\n"
#define pii pair<int,int>
using namespace std;
void solve(){
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000";
		return ;
	}
	cout << "1";
	if(s1[0] != s2[0] || s1[1] != s2[1]){
		cout << "000";
		return ;
	}
	cout << "1";
	if(s1[2] <= 'C' && s2[2] > 'C' || s1[2] > 'C' && s2[2] <= 'C'){
		cout << "00";
		return; 
	}
	cout << "1";
	if(abs(s1[2] - s2[2]) == 1 || abs(s1[2] - s2[2]) == 'F' - 'D'){
		cout << "1";
	}else{
		cout << "0";
	}
	return; 
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	fast;
	int T = 1;
//	cin >> T;
	while(T --){
		solve();
	}
	return 0;
}
