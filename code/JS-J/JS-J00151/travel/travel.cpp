#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool sd1,sd2;
bool sp;
bool f(char x){
	if(x=='F' || x=='D') return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	sd1=f(s1[2]);
	sd2=f(s2[2]);
	if(sd1==sd2){
		cout << 1;
		if(sd1){
			cout << 1;
			return 0;
		}else{
			if(s1[2]=='B' || s2[2]=='B') cout << 1;
			else cout << 0;
		}
	}else{
		cout << "00";
		return 0;
	}
	return 0;
}
