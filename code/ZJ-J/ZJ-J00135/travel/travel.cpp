#include <bits/stdc++.h>
using namespace std;
string rc,xc,rw,xw;
int rp,xp;
bool pc(char c){
	if(c=='A'||c=='B'||c=='C')return 1;
	else return 0;
}
bool px(char a,char b){
	if(a>b)swap(a,b);
	if(a=='A'&&b=='B')return 1;
	if(a=='B'&&b=='C')return 1;
	if(a=='D'&&b=='F')return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rw>>xc>>xw;
	if(rc==xc){
		cout<<"1";
		rp=(rw[0]-'0')*10+(rw[1]-'0');
		xp=(xw[0]-'0')*10+(xw[1]-'0');
		if(rp==xp){
			cout<<"1";
			if(pc(rw[2])==pc(xw[2])){
				cout<<"1";
				if(px(rw[2],xw[2])){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
