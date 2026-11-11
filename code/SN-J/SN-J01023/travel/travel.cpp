#include<bits/stdc++.h>
using namespace std;
int c1,c2,l1,l2,p1,p2,d1,d2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='A'){
		l1=5;
	}
	else if(s1[2]=='B') l1=4;
	else if(s1[2]=='C') l1=3;
	else if(s1[2]=='D') l1=2;
	else if(s1[2]=='f') l1=1;
	if(s2[2]=='A'){
		l1=5;
	}
	else if(s2[2]=='B') l2=4;
	else if(s2[2]=='C') l2=3;
	else if(s2[2]=='D') l2=2;
	else if(s2[2]=='F') l2=1;
	p1=int(s1[0]-'0')*10+int(s1[1]-'0');
	p2=int(s2[0]-'0')*10+int(s2[1]-'0');
	if(1<=l1&&l1<=2) d1=2;
	else d1=1;
	if(1<=l2&&l2<=2) d2=2;
	else d2=1;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<'1';;
		if(p1!=p2){
			cout<<"000";
			return 0;
		}
		else{
			cout<<"1";
			if(d1==d2){
				cout<<'1';
				if(l1-l2==1||l2-l1==-1){
					cout<<'1';
				}
				else cout<<'0';
			} 
			else cout<<"00";
			return 0;
		} 
	}
	return 0;
}
