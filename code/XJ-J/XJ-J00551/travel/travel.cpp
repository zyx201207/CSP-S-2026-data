#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string caa,cab,seata,seatb;
	cin >> caa >> seata >> cab >> seatb;
	int len1 = seata.length();
	int len2 = seatb.length();
	if(caa == cab){
		cout << "1";
	}else{
		cout << "0000";
		return 0;
	}
	if(seata[0] == seatb[0]  and  seata[1] == seatb[1]){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
	if(seata[2] == 'A' || seata[2]=='B' || seata[2]=='C'){
		cout << 1;
	}else if(seatb[2] == 'D' || seatb[2] =='E'){
		cout << "1";
	}else{
		cout <<"00";
		return 0;
	}
	if(seata[2]=='A'){
		if(seatb[2]=='B'){
			cout << "1";
		}else{
			cout << "0";
		}
	}else if(seata[2] == 'B'){
		if(seatb[2] == 'A' || seatb[3] == 'C'){
			cout << "1";
		}else{
			cout << "0";
		}
	}else if(seata[2] =='C'){
		if(seatb[2] == 'B'){
			cout << "1";
		}else{
			cout << "0";
		}
	}else if(seatb[2] =='D' || seatb[2] == 'E'){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
}

