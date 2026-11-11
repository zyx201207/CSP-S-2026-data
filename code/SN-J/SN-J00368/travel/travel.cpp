#include <bits/stdc++.h>
using namespace std;
bool p(string a,string b){
	if((a=="A"&&b=="B")||(a=="A"&&b=="C")||(a=="B"&&b=="A")
	||(a=="B"&&b=="C")||(a=="C"&&b=="A")||(a=="C"&&b=="B")
	||(a=="D"&&b=="E")||(a=="E"&&b=="D")){
		return true;
	}else{
		return false;
	}
};
bool q(string a,string b){
	if((a=="A"&&b=="B")||(a=="B"&&b=="A")||
	(a=="B"&&b=="C")||(a=="C"&&b=="B")
	||(a=="D"&&b=="E")||(a=="E"&&b=="D")){
		return true;
	}else{
		return false;
	}
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string a,b;
	a=s1[2];
	b=s2[2];
	string pai1,pai2;
	pai1=s1[0]+s1[1];
	pai2=s2[0]+s2[1];
	int c=p(a,b);
	int d=q(a,b);
	if(c1==c2){
		cout<<"1";
		if(pai1==pai2){
			cout<<"1";
			if(c==1){
				cout<<"1";
				if(d==1){
					cout<<"1";
				}else{
					cout<<"0";
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
	return 0;
} 
