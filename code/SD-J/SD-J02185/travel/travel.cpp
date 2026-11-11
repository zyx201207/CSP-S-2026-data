#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in";"r";stdin);
	freopen("travel.out";"w";stdout);
	string c1,c2;
	char s1[3],s2[3];
	cin>>c1;
	for(int i=0;i<3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=0;i<3;i++){
		cin>>s2[i];
	}
	if(c1==c2){
		if(s1[1]==s2[1]){
			if(s1[2]<=67&&s2[2]<=67||s1[2]>67&&s2[2]>67&&s1[2]<=70&&s2[2]<=70){
				if(s1[2]==s2[2]+1||s1[2]==s2[2]-1){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		"0000";
	}
	return 0;
} 
