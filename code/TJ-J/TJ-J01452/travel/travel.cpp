#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			int a=0,b=0;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				a=1;
			}else{
				a=2;
			}
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				b=1;
			}else{
				b=2;
			}
			if(a==b){
				cout<<"1";
				if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
					cout<<"0"<<endl;
				}else{
					cout<<"1"<<endl;
				}
			}else{
				cout<<"00"<<endl;
			}
		}else{
			cout<<"000"<<endl;
		}
	}else{
		cout<<"0000"<<endl;
	}
	return 0;
}
