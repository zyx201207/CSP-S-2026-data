#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb){
		if(sa[0]==sb[0]&&sa[1]==sb[1]){
			if(sa[2]=='A'&&sb[2]!='D'&&sb[2]!='F'||sa[2]=='B'&&sb[2]!='D'&&sb[2]!='F'||sa[2]=='C'&&sb[2]!='D'&&sb[2]!='F'||sa[2]=='D'&&sb[2]=='F'||sa[2]=='F'&&sb[2]=='D'){
				if(sa[2]=='A'&&sb[2]=='B'||sa[2]=='B'&&sb[2]=='A'||sa[2]=='B'&&sb[2]=='C'||sa[2]=='C'&&sb[2]=='B'||sa[2]=='D'&&sb[2]=='F'||sa[2]=='F'&&sb[2]=='D'){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
/*
A B
A C
B A
B C
C A
C B
D E
E D
*/