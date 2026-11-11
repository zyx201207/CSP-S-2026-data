#include<iostream> 
#include<string>
#include<cmath>
using namespace std;
string c1,s1,c2,s2;
int getp(string c1){
	return (c1[0]-'0')*10+c1[1]-'0';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else{
		cout<<'1';
		if(getp(s1)==getp(s2)){
			cout<<'1';
			if(s1[2]>'C'==s2[2]>'C'){
				cout<<'1';
				if(abs(s1[2]-s2[2])==1){
					cout<<'1';
				}
				else{
					cout<<'0';
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
	return 0;
}
