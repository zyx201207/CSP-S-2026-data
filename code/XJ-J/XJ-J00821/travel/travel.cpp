#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2){
		cout<<"1";
		if (s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if (s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if (s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					cout<<"1";
					switch(s1[2]){
						case 'A':{
							if (s2[2]=='B'){
								cout<<"1\n";
								return 0;
							}else{
								cout<<"0\n";
								return 0;
							}
							break;
						}
						case 'B':{
							if (s2[2]=='C'||s2[2]=='A'){
								cout<<"1\n";
								return 0;
							}else{
								cout<<"0\n";
								return 0;
							}
							break;
						}
						case 'C':{
							if (s2[2]=='B'){
								cout<<"1\n";
								return 0;
							}else{
								cout<<"0\n";
								return 0;
							}
							break;
						}
					}
				}else{
					cout<<"00\n";
					return 0;
				}
			}else{
				if (s2[2]=='D'||s2[2]=='F'){
					cout<<"1";
					switch(s1[2]){
						case 'D':{
							if (s2[2]=='F'){
								cout<<"1\n";
								return 0;
							}else{
								cout<<"0\n";
								return 0;
							}
							break;
						}
						case 'F':{
							if (s2[2]=='D'){
								cout<<"1\n";
								return 0;
							}else{
								cout<<"0\n";
								return 0;
							}
							break;
						}
					}
				}else{
					cout<<"00\n";
					return 0;
				}
			}
		}else{
			cout<<"000\n";
			return 0;
		}
	}else{
		cout<<"0000\n";
		return 0;
	}
	return 0;
}