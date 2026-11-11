#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c3;
	string c2,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c2[0]==c4[0] and c2[1]==c4[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c2[0]==c4[0] and c2[1]==c4[1] and c2[2]=='D' and c2[2]=='F' or c4[2]=='D' and c4[2]=='F'){
		cout<<1;
	}else if(c2[0]==c4[0] and c2[1]==c4[1] and c2[2]=='A' and c2[2]=='B' and c2[2]=='C' or c4[2]=='C' and c4[2]=='A' and c4[2]=='B'){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c2[0]==c4[0] and c2[1]==c4[1] and c2[2]=='A' and c2[2]=='B' or c4[2]=='A' and c4[2]=='B'){
		cout<<1;
	}else if(c2[0]==c4[0] and c2[1]==c4[1] and c2[2]=='B' and c2[2]=='C' or c4[2]=='B' and c4[2]=='C'){
		cout<<1;
	}else if(c2[0]==c4[0] and c2[1]==c4[1] and c2[2]=='C' and c2[2]=='D' or c4[2]=='C' and c4[2]=='D'){
		cout<<1;
	}else if(c2[0]==c4[0] and c2[1]==c4[1] and c2[2]=='D' and c2[2]=='E' or c4[2]=='D' and c4[2]=='E'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}