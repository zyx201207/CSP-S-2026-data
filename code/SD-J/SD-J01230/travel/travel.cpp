#include<bits/stdc++.h>
using namespace std;
bool check (char x,char y){
	if(x=='D'&&y=='F') return 1;
	else if(x=='F'&&y=='D') return 1;
	else if(x=='A'&&y=='B') return 1;
	else if(x=='B'&&y=='A') return 1;
	else if(x=='C'&&y=='A') return 1;
	else if(x=='A'&&y=='C') return 1;
	else if(x=='B'&&y=='C') return 1;
	else if(x=='C'&&y=='B') return 1;
	else return 0;
}
string cx,cy,sx,sy;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>sx>>cy>>sy;
	char u=sx[2],v=sy[2];
	if(cx==cy){
		if(sx[0]==sy[0]&&sx[1]==sy[1]){
			if(check(u,v)!=0){
				if(abs(u-v)==1){
					cout<<"1111";
				}
				else {
					cout<<"1110";
				}
			}
			else {
				cout<<"1100";
			}
		}
		else {
			cout<<"1000";
		}
	}
	else cout<<"0000";
	return 0;
} 
