#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	string p1,p2;
	p1 = s1[0]+s1[1];
	p2 = s2[0]+s2[1];
	if(p1 == p2){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	char w1=s1[2],w2=s2[2];
	int c=0;
	if(w1 == 'A' || w1 == 'B' || w1 == 'C'){
		if(w2 == 'A' || w2 == 'B' || w2 == 'C'){
			cout<<"1";
			c = 1;
		}
	}
	else if(w1 == 'D' || w1 == 'F'){
		if(w2 == 'D' || w2 == 'F'){
			cout<<"1";
			c = 1;
		}
	}
	if(c == 0){
		cout<<"00";
		return 0;
	}
	if((w1 == 'A' && w2 == 'B') || (w1 == 'B' && w2 == 'A') || (w1 == 'B' && w2 == 'C') || (w1 == 'C' && w2 == 'B') || (w1 == 'D' && w2 == 'F') || (w1 == 'F' && w2 == 'D')){
		cout<<"1";
	}
	else{
		cout<<"0"; 
	}
	return 0;
} 
