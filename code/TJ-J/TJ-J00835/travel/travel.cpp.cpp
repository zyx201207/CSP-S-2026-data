#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1, c2;
	string s1[2],s2[2];
	char x,s;
	cin>>c1;
	for(int i=1;i<=3;i++){
		if(i==3){
			cin>>x;
		}
		else{
			cin>>s1[i];
		}
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
		if(i==3){
			cin>>x;
		}
		else{
			cin>>s2[i];
		}
	}
	if(c1!=c2) {
		cout<<"0000";
	}
	else if(c1==c2){
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
			if((x=='D'&& s=='C')||(x=='C'&& s=='D')){
				cout<<"1100";
			}
			else{
				if(s1-s2==1||s2-s1==1){
					cout<<"1111";
				}
			}
		}
		else{
			cout<<"1000";
		}
	}	
	return 0;
}
