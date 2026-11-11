#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char x=s1[2];
	char y=s2[2];
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
    		cout<<"1";
    		if(x=='A'&&y=='B'){
    			cout<<"11";
			}else if(x=='B'&&y=='A'){
    			cout<<"11";
			}else if(x=='B'&&y=='C'){
    			cout<<"11";
			}else if(x=='C'&&y=='B'){
    			cout<<"11";
			}else if(x=='D'&&y=='F'){
    			cout<<"11";
			}else if(x=='F'&&y=='D'){
    			cout<<"11";
			}else if(x=='A'&&y=='C'){
    			cout<<"10";
			}else if(x=='C'&&y=='A'){
    			cout<<"10";
			}else if(x=='A'&&y=='D'){
				cout<<"00";
			}else if(x=='A'&&y=='F'){
				cout<<"00";
			}else if(x=='B'&&y=='D'){
				cout<<"00";
			}else if(x=='B'&&y=='F'){
				cout<<"00";
			}else if(x=='C'&&y=='D'){
				cout<<"00";
			}else if(x=='C'&&y=='F'){
				cout<<"00";
			}else if(x=='D'&&y=='A'){
				cout<<"00";
			}else if(x=='D'&&y=='B'){
				cout<<"00";
			}else if(x=='D'&&y=='C'){
				cout<<"00";
			}else if(x=='F'&&y=='A'){
				cout<<"00";
			}else if(x=='F'&&y=='B'){
				cout<<"00";
			}else if(x=='F'&&y=='C'){
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
    }else{
		cout<<"0000";
	}
	return 0;
}
