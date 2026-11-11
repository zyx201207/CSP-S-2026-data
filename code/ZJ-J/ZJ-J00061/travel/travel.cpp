#include<bits/stdc++.h>
using namespace std;

int main()
{
	//1.0s 1024MB
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string P1_num;cin >> P1_num;
	string p1_s;cin >> p1_s;
	string P2_num;cin >> P2_num;
	string p2_s;cin >> p2_s;
	
	if(P1_num == P2_num){
		cout << '1';
	}else{
		cout << "0000";
		return 0;
	}
	int p1_ans = (p1_s[0] - '0')*10 + (p1_s[1] - '0');
	int p2_ans = (p2_s[0] - '0')*10 + (p2_s[1] - '0');
	if(p1_ans == p2_ans){
		cout << '1';
	}else{
		cout << "000";
		return 0;
	}
	
	bool p1_side = 0;
	bool p2_side = 0;
	
	if(p1_s[2] == 'F' || p1_s[2] == 'D') p1_side = 1;
	else p1_side = 0;
	if(p2_s[2] == 'F' || p2_s[2] == 'D') p2_side = 1;
	else p1_side = 0;
	
	if(p1_side == p2_side && p1_side == 1){
		cout << "11";
		return 0;
	}
	if(p1_side == p2_side){
		cout << '1';
	}else{
		cout << "00";
		return 0;
	}
	
	if((p1_s[2] == 'A' && p2_s[2] == 'C' ) || ( p1_s[2] == 'C' && p2_s[2] == 'A')){
		cout << '0';
	}else{
		cout << '1';
	}
	
	return 0;
}
