#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int p1,p2,len;
char st1,st2;
bool xl(char x,char y){
	if(x=='A'&&y=='B') return 1;
	if(x=='B'&&(y=='A'||y=='C')) return 1;
	if(x=='C'&&y=='B') return 1;
	if(x=='D'&&y=='F') return 1;
	if(x=='F'&&y=='D') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	len=s1.size();
	st1=s1[len-1];
	st2=s2[len-1];
	p1=(s1[0]-'0')*10+(s1[1]-'0');
	p2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2){
		cout<<"1";
		if(p1==p2){
			cout<<"1";
			if(st1<='C'&&st2<='C'){
				cout<<"1";
				if(xl(st1,st2)) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
/*
int rp=0;
while(1) rp++;
*/
