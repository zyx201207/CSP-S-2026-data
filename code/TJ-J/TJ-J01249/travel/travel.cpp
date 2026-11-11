#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int a=0,b=0,c=0;
	cin>>c1>>s1>>c2>>s2;
	int h1,h2;
	h1=(c1[0]-'0')*10+c1[1]-'0';
	h2=(c2[0]-'0')*10+c2[1]-'0';
	if(h1==h2){
		h1=(s1[0]-'0')*10+s1[1]-'0';
		h2=(s2[0]-'0')*10+s2[1]-'0';
		if(h1==h2){
			char t1=s1[2],t2=s2[2];
			if((t1=='A'||t1=='B'||t1=='C')&&(t2=='A'||t2=='B'||t2=='C')){
				if(t1=='B'||t2=='B'){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
				return 0;
			}
			if((t1=='D'||t1=='F')&&(t2=='D'||t2=='F')){
				cout<<"1111";
				return 0;
			}
			cout<<"1100";
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
