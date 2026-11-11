#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	for(int i=0;i<a1.size();i++){
		if(a1[i]!=b1[i]){
			cout<<"0000";
			return 0;
		}
	}
	for(int i=0;i<2;i++){
		if(a2[i]!=b2[i]){
			cout<<"1000";
			return 0;
		}
	}
	if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C'){
		if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'){
			
		}else{
			cout<<"1100";
			return 0;
		}
	}else{
		if(a2[2]=='D'||a2[2]=='F'){
			cout<<"1111";
			return 0;
		}else{
			cout<<"1100";
			return 0;
		}
	}
	if(a2[2]=='A'){
		if(b2[2]=='B'){
			cout<<"1111";
			return 0;
		}else{
			cout<<"1110";
			return 0;
		}
	}
	if(a2[2]=='B'){
		if(b2[2]=='A'||b2[2]=='C'){
			cout<<"1111";
			return 0;
		}else{
			cout<<"1110";
			return 0;
		}
	}
	if(a2[2]=='C'){
		if(b2[2]=='B'){
			cout<<"1111";
			return 0;
		}else{
			cout<<"1110";
			return 0;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}