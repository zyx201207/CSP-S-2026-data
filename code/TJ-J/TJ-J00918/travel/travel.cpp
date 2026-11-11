#include<bits/stdc++.h>
using namespace std;
string c1;
string c2;
string s1;
string s2;
char h1,h2;
string p1,p2;
string p12,p22;
char b1,b2;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
cin >> c1 >> s1 >> c2 >> s2;
for (int i=0;i<=2;i++){
	h1=s1[i];
	h2=s2[i];
}
for (int i=2;i>=0;i--){
	p1=s1[i];
	p2=s2[i];
}
for (int i=1;i>=0;i--){
	p12=s1[i+1];
	p22=s2[i+1];
}
if (h1=='A'|| h1=='B' || h1=='C' ){
	b1='x';
}
else {
	b1='s';
}
if (h2=='A' || h2=='B' || h2=='C' ){
	b2='x';
}
else {
	b2='s';
}
	for(int i=1;i<=1;i++){
		if (c1==c2){
			cout << 1;
			if (p1==p2 && p12==p22){
				cout << 1;
				if (b1==b2){
					cout << 1;
					if ((h1=='A'&& h2=='B')||(h1=='B'&& h2=='C')||(h1=='B'&& h2=='A')||(h1=='C'&& h2=='B')||(h1=='D'&& h2=='F')||(h1=='F'&& h2=='D')){
						cout << 1;
					}
					else {
						cout << "0";
					}
				}
				else{
					cout << "00";
				}
				
			}
			else {
				cout << "000";
				break;
			}
		}
		else {
			cout <<"0000";
			break;
		}
	}
	return 0;
}
