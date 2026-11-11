#include<bits/stdc++.h>
using namespace std;
int R,X;
string R1,X1,cnt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> R >> R1 >> X >> X1;
	if(R==X){
		cnt = "1";
	}
	else{
		cnt = "0000";
		cout << cnt;
		return 0;
	}
	if(R1[0] == X1[0]&&R1[1] == X1[1]){
		cnt += "1";
	}
	else if(cnt=="1"){
		cnt = "1000";
		cout << cnt;
		return 0;
	}
	else{
		cnt = "0000";
		cout << cnt;
		return 0;
	}
	if(R1[2]=='A'&&X1[2]=='B'||X1[2]=='B'&&R1[2]=='C'||X1[2]=='D'&&R1[2]=='F'||R1[2]=='B'&&X1[2]=='A'||X1[2]=='C'&&R1[2]=='B'||X1[2]=='F'&&R1[2]=='D'){
		cout << "1111";
	}
	else if(R1[2]=='C' && X1[2]=='D'||R1[2]=='D' && X1[2]=='C'){
		cout << "1100";
		return 0;
	}
	else if(R1[2]=='A' && X1[2]=='C'||R1[2]=='C' && X1[2]=='A'){
		cout << "1110";
		return 0;
	}
	else{
		cout << "1100";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
