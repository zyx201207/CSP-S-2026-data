#include <bits/stdc++.h>
using namespace std;
char room[4],seat[6];
int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<2;i++){
		for(int j=0+i*2;j<2+i*2;j++)
			cin >> room[j];
		for(int j=0+i*3;j<3+i*3;j++)
			cin >> seat[j];
	}
	if(room[0]!=room[2]||room[1]!=room[3]){
		cout << "0000"; return 0;
	}
	if(seat[0]!=seat[3]&&seat[1]!=seat[4]){
		cout << "1000"; return 0;
	}
	if(seat[2]=='A'||seat[2]=='B'||seat[2]=='C'){
		if(seat[5]=='A'||seat[5]=='B'||seat[5]=='C'){
			if(seat[2]-'0'==seat[5]-'0'+1||seat[2]-'0'==seat[5]-'0'-1){
				cout << "1111"; return 0;
			}else{
				cout << "1110"; return 0;
			}
		}
		else{
			cout << "1100"; return 0;
		}
	}
	if(seat[2]=='D'||seat[2]=='F')
		if(seat[5]=='D'||seat[5]=='F'){
			cout << "1111"; return 0;
		}
	return 0;
}

