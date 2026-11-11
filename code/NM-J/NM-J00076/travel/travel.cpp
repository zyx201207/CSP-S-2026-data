#include<iostream>
using namespace std;
string c1,s1,c2,s2,a1,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else{
		cout<<"1";
		a1=s1[0];
		a2=s2[0];
		a1+=s1[1];
		a2+=s2[1];
		if(a1!=a2){
			cout<<"000";
		}
		else{
			cout<<"1";
			a1=s1[2];
			a2=s2[2];
			if(((a1=="A"||a1=="B"||a1=="C")&&(a2=="A"||a2=="B"||a2=="C"))||((a1=="D"||a1=="F")&&(a2=="D"||a2=="F"))){
				cout<<"1";
				if(((a1=="D"&&a2=="F")||(a1=="F"&&a2=="D"))||((a1=="A"&&a2=="B")||(a1=="C"&&a2=="B")||(a1=="B"&&(a2=="A"||a2=="B")))){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
	}
	return 0;
}
