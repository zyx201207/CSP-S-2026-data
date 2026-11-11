#include <bits/stdc++.h>
using namespace std;



int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ca,sa,cb,sb;
	bool chexiang,row,yice,xianglin;
	cin >> ca >> sa >> cb >> sb;
	chexiang = (ca == cb);
	row =  (sa[0]==sb[0]&&sa[1] == sa[1]);
	if((sa[2]=='C'||sa[2]=='D')&&(sb[2]=='D' || sb[2] == 'C')&&sa[2]!=sb[2]){
		yice = 0;
	}
	else{
		yice = (sa[2]-sb[2] < 2) && (sb[2] - sa[2] <2);
	}
	xianglin = (chexiang && row && yice);
	cout << chexiang << row << (row && yice) << xianglin;
	return 0;
}
