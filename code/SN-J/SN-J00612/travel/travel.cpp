#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			cout<<"1";
			if(s1[2]<='C' and s2[2]<='C' or s1[2]>='D' and s2[2]>='D'){
				cout<<"1";
				if(s1[2]=='F')
					s1[2]='E';
				if(s2[2]=='F')
					s2[2]='E';
				if(abs(s1[2]-s2[2])==1)
					cout<<"1";
				else
					cout<<"0";
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	return 0;
}
