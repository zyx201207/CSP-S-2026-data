#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cm,sn;
	cin>>cr>>sr>>cm>>sn;
	string s="";
	string z="",c=""; 
	char a,b;
	for(int i=0;i<sr.size();i++){
		if(sr[i]>='0'&&sr[i]<='9') z+=sr[i];
		if(sr[i]=='A'||sr[i]=='B'||sr[i]=='C'||sr[i]=='D'||sr[i]=='F') a=sr[i];
	}
	for(int i=0;i<sn.size();i++){
		if(sn[i]>='0'&&sn[i]<='9') c+=sn[i];
		if(sn[i]=='A'||sn[i]=='B'||sn[i]=='C'||sn[i]=='D'||sn[i]=='F') b=sn[i];
	}
	if(cr==cm) s+='1';
	else {
		s+='0';
		s+='0';
		s+='0';
		s+='0';
		cout<<s;
		return 0;
	}
	if(z==c) s+='1';
	else{
		s+='0';
		s+='0';
		s+='0';
		cout<<s;
		return 0;
	}
	if(a=='A'&&b=='B'||a=='A'&&b=='C'||a=='D'&&b=='F'||a=='F'&&b=='D'||a=='B'&&b=='A'||a=='B'&&b=='C'||a=='C'&&b=='A'||a=='C'&&b=='B') s+='1';
	else{
		s+='0';
		s+='0';
		cout<<s;
		return 0;
	}
	if(a=='A'&&b=='B'||a=='B'&&b=='A'||a=='B'&&b=='C'||a=='D'&&b=='F'||a=='F'&&b=='D'||a=='C'&&b=='B') s+='1';
	else{
		s+='0';
		cout<<s;
		return 0;
	}
	cout<<s;
	return 0;	
}
