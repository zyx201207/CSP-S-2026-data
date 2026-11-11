#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cara,carb;
	string seata,seatb;
	cin>>cara>>seata>>carb>>seatb;
	if(cara=="01" || cara=="16" || carb=="01" || carb=="16") return 0;//if一
	if(cara==carb) {
		cout<<"1";
	} else {
		cout<<"0000";
		return 0;
	}//同一车厢
	int hanga,hangb;
	hanga=seata[0]-'0'+seata[1]-'0';
	hangb=seatb[0]-'0'+seatb[1]-'0';
	if(hanga==hangb) {
		cout<<"1";
	} else {
		cout<<"000";
		return 0;
	}
	int pan=0;
	if(seata[2]=='A' and seatb[2]=='C') {
		cout<<"10";
		pan++;
	}
	if(seata[2]=='C' and seatb[2]=='A') {
		cout<<"10";
		pan++;
	}
	if(pan==1) {
		return 0;
	}
	if(seata[2]-seatb[2]>=2 or seatb[2]-seata[2]>=2) {
		cout<<"00";
		return 0;
	}
	if(seata[2]=='C' && seatb[2]=='D') {
		cout<<"00";
		return 0;
	}
	if(seata[2]-seatb[2]==1 or seatb[2]-seata[2]==1) {
		cout<<"11";
		return 0;
	}
	return 0;
}
