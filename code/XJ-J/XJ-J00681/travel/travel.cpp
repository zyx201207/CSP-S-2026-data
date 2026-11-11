#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1;
	string s1;
	string c2;
	string s2;
	cin>>c1>>s1>>c2>>s2;

	if(c1==c2){
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			if(s1[2]=='A' && s2[2]=='B' or s1[2]=='B' && s2[2]=='A' or s1[2]=='C' && s2[2]=='D' or s2[2]=='F' or s1[2]=='D' && s2[2]=='C' or s2[2]=='F' or s1[2]=='F' && s2[2]=='C' or s2[2]=='D'){
				if(s1[2]=='A' && s2[2]=='B' or s1[2]=='B' && s2[2]=='A' or s1[2]=='B' && s2[2]=='C' or s1[2]=='C' && s2[2]=='B' or s1[2]=='C' && s2[2]=='D' or s1[2]=='D' && s2[2]=='C' or s1[2]=='D' && s2[2]=='F' or s1[2]=='F' && s2[2]=='D'){
					cout<<1111;
				}else{
					cout<<1110;
					return 0;
				}
			}else{
				cout<<1100;
				return 0;	
			}
		}else{
			cout<<1000;
			return 0;
		}
	}else{
		cout<<0000;
		return 0;
	}

	return 0;
}