#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1;
	string s2,c2;
	cin>>c1>>s1>>c2>>s2;
	bool c=false,p=false,ce=false,between=false;
	if(c1!=c2) {
		cout<<c<<p<<ce<<between;
		return 0;
	}else{
		c=true;
		if(s1[0]==s2[0]){
			p=true;
			if(s1[1]==s2[1]){
				ce=true;
				if(s1[2]=='A'){
					if(s2[2]=='B'){
						between=true;
					}else{
						between=false;
					}
				}
				if(s1[2]=='B'){
					if(s2[2]=='A'){
						between=true;
					}else if(s2[2]=='C'){
						between=true;
					}else{
						between=false;
					}
				}
				if(s1[2]=='C'){
					if(s2[2]=='B'){
						between= true;
					}else{
						between=false;
					}
				}
				if(s1[2]=='D'){
					if(s2[2]=='F'){
						between=true;
					}else{
						between=false;
					}
				}
				if(s1[2]=='F'){
					if(s2[2]=='D'){
						between=true;
					}else{
						between=false;
					}
				}
			}else{
				ce=false;
				between=false;
			}
		}else{
			p=false;
			ce=false;
			between=false;
		}
	}
	cout<<c<<p<<ce<<between;
	return 0;
} 
