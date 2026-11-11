#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int f1=true,f2=true,f3=true;
	for(int i=0;i<3;i++){
		if(c1[i]!=c2[i]){
			f1=false;
			cout<<"0";
			break;
		}
	}	
	if(f1==true){
		cout<<"1";
	}
	for(int i=0;i<3;i++){
		if(s1[i]!=s2[i]){
			f2=false;
			cout<<"0";
			break;
		}
	}	
	if(f1==true and f2==true){
		cout<<"1";
	}
	if(s1[2]=='A' or s1[2]=='B' or s1[2]=='C'){
		if(s2[2]=='A' or s2[2]=='B' or s2[2]=='C'){
			if(f1==true and f2==true){
			cout<<"1";
			}
		}
	}
	else if(s1[2]=='D' or s1[2]=='F'){
		if(s2[2]=='D' or s2[2]=='F'){
			if(f1==true and f2==true){
			cout<<"11";
			}
		}
	}
	else{
		f3=false;
		cout<<"00";
	}
	if(f3==true){
		if(s1[2]=='D' or s1[2]=='F'){
			if(s2[2]=='D' or s2[2]=='F'){
				if(f1==true and f2==true){
					cout<<"1";
				}		
			}
		}
		if(f3==true){
			if(s1[2]=='A'){
				if(s2[2]=='B'){
					if(f1==true and f2==true){
						cout<<"1";
					}		
				}
			}
		}
		else{
			cout<<"1";
		}
	}

	return 0;
}
