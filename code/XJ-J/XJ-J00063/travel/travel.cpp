#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cr=0,sr=0,cx=0,sx=0;
bool check(char x ,char y){
	if( (x<='C' && y<='C') || (x>='D' && y>='D'))return true;
	else return false;
}
bool work(char x ,char y){
	if( (x=='A' && y=='B') || (x=='B' && y=='C') || (x=='D' && y=='F') || (x=='B' && y=='A') || (x=='C' && y=='B') || (x=='F' && y=='D'))return true;
	else return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++){
		cr=cr*10+(c1[i]-'0');
		cx=cx*10+(c2[i]-'0');
	}
	for(int i=0;i<=1;i++){
		sr=sr*10+(s1[i]-'0');
		sx=sx*10+(s2[i]-'0');		
	}
	if(cr==cx){
		if(sr==sx){
			if(check(s1[2],s2[2])){
				if(work(s1[2],s2[2])){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
