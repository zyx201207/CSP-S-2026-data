#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	char seat1=s1[2],seat2=s2[2];
	int sc1,sc2;
	if(seat1=='A'||seat1=='B'||seat1=='C')sc1=1;
	else sc1=2;
	if(seat2=='A'||seat2=='B'||seat2=='C')sc2=1;
	else sc2=2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(sc1==sc2){
				cout<<"1";
				if(sc1==1){
					if((seat1=='A'&&seat2=='C')||(seat1=='C'&&seat2=='A'))cout<<"0";
					else cout<<"1";
			    }
				if(sc1==2)cout<<"1";
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
