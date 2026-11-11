#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int s1,s2;
	string a1,a2;
	cin>>s1>>a1>>s2>>a2;
	if(s1!=s2){cout<<"0000";return 0;}
	int o=a1[0]-'0',o1=a1[1]-'0';
	int w=o*10+o1;
	o=a2[0]-'0';
	o1=a2[1]-'0';
	int w1=o*10+o1;
	if(w!=w1){cout<<"1000";return 0;}
	char c=a1[2],c1=a2[2];
	if(c=='D'){
		if(c1!='E'){cout<<"1100";return 0;}
	}
	else if(c=='E'){
		if(c1!='D'){cout<<"1100";return 0;}
	}
	else if(c1=='D'){
		if(c!='E'){cout<<"1100";return 0;}
	}
	else if(c1=='E'){
		if(c!='D'){cout<<"1100";return 0;}
	}
	if(abs(c-c1)!=1){cout<<"1110";return 0;}
	cout<<"1111";
	return 0;
}
