#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
		string n1=s1.substr(0,2),n2=s2.substr(0,2);
		if(n1!=n2){
			cout<<"000";
			return 0;
		}else{
			cout<<1;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]=='F'||s2[2]=='D'){
					cout<<"00";
					return 0;
				}
			}else if(s1[2]=='D'||s1[2]=='F'){
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					cout<<"00";
					return 0;
				}
			}
			cout<<1;
			if(s1[2]=='A')cout<<(s2[2]=='B');
			if(s1[2]=='B')cout<<(s2[2]=='C'||s2[2]=='A');
			if(s1[2]=='C')cout<<(s2[2]=='B');
			if(s1[2]=='D')cout<<(s2[2]=='F');
			if(s1[2]=='F')cout<<(s2[2]=='D');
		}
	}
	return 0;
}