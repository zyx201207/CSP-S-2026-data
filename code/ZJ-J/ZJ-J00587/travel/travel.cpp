#include<iostream>
#include<cmath>
using namespace std;
string c,s,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c2>>s2;
	if(c==c2){
		cout<<1;
		if(s[0]==s2[0]&&s[1]==s2[1]){
			cout<<1;
			if(s[2]<'D'&&s2[2]<'D'||s[2]>'C'&&s2[2]>'C'){
				cout<<1;
				if(abs(s[2]-s2[2])==1||s[2]=='D'&&s2[2]=='F'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
