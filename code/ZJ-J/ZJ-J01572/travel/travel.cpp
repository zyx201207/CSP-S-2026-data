#include<bits/stdc++.h>
using namespace std;
int pd[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool flag=true;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i]){
			flag=false;
		}
	}
	if(!flag){
		cout<<"1000";
		return 0;
	}
	int guodao1=2,guodao2=2;
	switch(s1[2]){
		case 'A':
		case 'B':
		case 'C':
			guodao1=1;
			break;	
	}
	switch(s2[2]){
		case 'A':
		case 'B':
		case 'C':
			guodao2=1;
			break;	
	}
	if(guodao1!=guodao2){
		cout<<"1100";
		return 0;
	}
	int a=s1[2]-s2[2];
	if(a!=1&&a!=-1){
		cout<<"1110";
		return 0;
	}	
	cout<<"1111";
	return 0;
}