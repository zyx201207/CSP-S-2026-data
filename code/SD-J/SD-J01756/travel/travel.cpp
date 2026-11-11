#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else{
		cout<<"1";
		int a=(s1[0]-'0')*10+(s1[1]-'0');
		int b=(s2[0]-'0')*10+(s2[1]-'0');
		if(a!=b){
			cout<<"000";
		}
		else{
			cout<<"1";
			char p1=s1[2];
			char p2=s2[2];
			if(p1<='C'&&'C'<p2){
				cout<<"00";
			}
			else{
				cout<<"1";
				if((p1=='C'&&p2=='A')||(p1=='A'&&p2=='C')){
					cout<<"0";
				}
				else{
					cout<<"1";
				}
			}
		}
	}
	return 0;
}
