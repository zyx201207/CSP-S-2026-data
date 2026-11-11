#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool checksd(char pos1,char pos2){
	if(pos1=='D'&&pos2=='F')return 1;
	else if(pos1=='F'&&pos2=='D')return 1;
	else if(pos1=='A'&&pos2=='B')return 1;
	else if(pos1=='A'&&pos2=='C')return 1;
	else if(pos1=='B'&&pos2=='A')return 1;
	else if(pos1=='B'&&pos2=='C')return 1;
	else if(pos1=='C'&&pos2=='A')return 1;
	else if(pos1=='C'&&pos2=='B')return 1;
	return 0;
}
bool checkbs(char pos1,char pos2){
	if(pos1=='D'&&pos2=='F')return 1;
	else if(pos1=='F'&&pos2=='D')return 1;
	else if(pos1=='A'&&pos2=='B')return 1;
	else if(pos1=='B'&&pos2=='A')return 1;
	else if(pos1=='B'&&pos2=='C')return 1;
	else if(pos1=='C'&&pos2=='B')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string row1,row2;
	row1+=s1[0];row1+=s1[1];
	row2+=s2[0];row2+=s2[1];
	char pos1=s1[2],pos2=s2[2];
	if(c1==c2)printf("1");
	else {printf("0000");return 0;}
	if(row1==row2)printf("1");
	else {printf("000");return 0;}
	if(checksd(pos1,pos2))printf("1");
	else {printf("00");return 0;}
	if(checkbs(pos1,pos2))printf("1");
	else {printf("0");return 0;}
	return 0;
}
