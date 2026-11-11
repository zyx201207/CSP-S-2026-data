#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char a=s1[2];
	char b=s2[2];
	bool flg2=false;
	if(a=='A'&&b=='B')flg2=true;
	else if(a=='B'&&b=='A')flg2=true;
	else if(a=='B'&&b=='C')flg2=true;
	else if(a=='C'&&b=='B')flg2=true;
	else if(a=='D'&&b=='F')flg2=true;
	else if(a=='F'&&b=='D')flg2=true;
	
	bool flg1=false;
	if(a=='A'&&b=='B')flg1=true;
	else if(a=='B'&&b=='A')flg1=true;
	else if(a=='B'&&b=='C')flg1=true;
	else if(a=='C'&&b=='B')flg1=true;
	else if(a=='A'&&b=='C')flg1=true;
	else if(a=='C'&&b=='A')flg1=true;
	else if(a=='D'&&b=='F')flg1=true;
	else if(a=='F'&&b=='D')flg1=true;
	
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(flg1==true){
				cout<<"1";
				if(flg2==true){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
