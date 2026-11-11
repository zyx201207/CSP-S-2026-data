#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int f=1;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout << "1";	
	}else{
		cout << "0000\n";
		return 0;	
	}
	for(int i=0;i<2;i++){
		if(s1[i]==s2[i]) continue;
		else f=0;
	}
	if(f==1){
		cout << "1";	
	}else{
		cout << "000\n";
		return 0;	
	}
	
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')){
		cout << "11\n";	
		return 0;
	}else if((s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')){
		cout << "11\n";
		return 0;	
	}else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
		cout << "11\n";
		return 0;
	}
	
	if(s1[2]=='A'&&s2[2]=='C'){
		cout << "10\n";
	}else if(s1[2]=='C'&&s2[2]=='A'){
		cout << "10\n";
	}else{
		cout << "00\n";
	}
	return 0;
}
