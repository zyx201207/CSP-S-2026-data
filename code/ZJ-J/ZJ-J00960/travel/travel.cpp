#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		a=1;
	}
	else{
		a=2;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		b=1;
	}
	else{
		b=2;
	}
	if(c1==c2){
		cout<<"1";
		if(s1[1]==s2[1]&&s1[0]==s2[0]){
			cout<<"1";
			if(a==b){
				cout<<"1";
				char c=s1[2],d=s2[2];
				if(((c+1)==d&&c!='C')||((d+1)==c&&d!='C')){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
