#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.txt","r",stdin);
	freopen("travel2.txt","w",stdout);
	string c1,c2,d1,d2;
	cin>>c1>>c2>>d1>>d2;
	if(c1==d1){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	string s1=c2.substr(0,2);
	string s2=d2.substr(0,2);
	if(s1==s2){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(c2[2]=='A'){
		if(d2[2]=='B'){
			cout<<"11";
			return 0;
		}
		else if(d2[2]=='C'){
			cout<<"10";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(c2[2]=='B'){
		if(d2[2]=='A'||d2[2]=='C'){
			cout<<"11";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(c2[2]=='C'){
		if(d2[2]=='B'){
			cout<<"11";
			return 0;
		}
		else if(d2[2]=='A'){
			cout<<"10";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(c2[2]=='D'){
		if(d2[2]=='F'){
			cout<<"11";
			return 0;
		} 
		else{
			cout<<"00";
		}
	}
	else{
		if(d2[2]=='D'){
			cout<<"11";
			return 0;
		} 
		else{
			cout<<"00";
		}
	}
	return 0;
} 
