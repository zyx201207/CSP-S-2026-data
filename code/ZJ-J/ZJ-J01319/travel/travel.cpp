#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2,ch1,ch2;
char idx1,idx2;
bool check(char x,char y){
	if(x<='C' and y<='C')
		return true;
	if(x>'C' and y>'C')
		return true;
	return false;
}
bool check2(char x,char y){
	if(x=='A' and y=='B')
		return true;
	if(x=='B' and y=='C')
		return true;
	if(x=='D' and y=='F')
		return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	ch1=(s1[0]-'0')*10+(s1[1]-'0');
	ch2=(s2[0]-'0')*10+(s2[1]-'0');
	idx1=s1[2],idx2=s2[2];
	if(c1==c2){
		cout<<"1";
		if(ch1==ch2){
			cout<<"1";
			if(check(idx1,idx2)){
				cout<<"1";
				if(check2(idx1,idx2)){
					cout<<"1";
				}else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}	
	else cout<<"0000";
}