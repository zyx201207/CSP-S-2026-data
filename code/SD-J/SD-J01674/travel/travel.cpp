#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<"1";
		int pos1=(a2[0]-'0')*10+a2[1]-'0',pos2=(b2[0]-'0')*10+b2[1]-'0';
		if(pos1==pos2){
			cout<<"1";
			int l1=0,l2=0;
			if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C')l1=0;
			else l1=1;
			if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C')l2=0;
			else l2=1;
			if(l1==l2){
				cout<<"1";
				if(abs(a2[2]-b2[2])==1){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
/*
*/
