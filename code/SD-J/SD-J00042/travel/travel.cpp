#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool check1(string b,string d){
	return b[0] == d[0] && b[1] == d[1];
}
bool check2(string b,string d){
	int ch1 = b[2],ch2 = d[2];
	if(ch1 < ch2) swap(ch1,ch2);
	if(ch1 == 'F' && ch2 == 'D') return 1;
	if(ch1 == 'C' && ch2 == 'B') return 1;
	if(ch1 == 'C' && ch2 == 'A') return 1;
	if(ch1 == 'B' && ch2 == 'A') return 1;
	return 0;
}
bool check3(string b,string d){
	int ch1 = b[2],ch2 = d[2];
	if(ch1 < ch2) swap(ch1,ch2);
	if(ch1 == 'F' && ch2 == 'D') return 1;
	if(ch1 == 'C' && ch2 == 'B') return 1;
	if(ch1 == 'B' && ch2 == 'A') return 1;
	return 0;	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a == c) cout << '1';
	else cout << '0';
	if(a == c && check1(b,d)) cout << '1';
	else cout << '0';
	if(a == c && check1(b,d) && check2(b,d)) cout << '1';
	else cout << '0';
	if(a == c && check1(b,d) && check2(b,d) && check3(b,d)) cout << '1';
	else cout << '0';
	return 0;
} 
