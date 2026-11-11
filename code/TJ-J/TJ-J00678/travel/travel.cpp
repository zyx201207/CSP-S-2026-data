#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	string a[10],b[10];
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=3;i++){
		a[i]=s1[i];
		b[i]=s2[i];
	}
	if(c1==c2){
		cout<<"1";
		if(a[0]==b[0]&&a[1]==b[1]){
			cout<<"1";
			if(a[2]=="A"&&b[2]=="B") cout<<"11";
			else if(a[2]=="A"&&b[2]=="C") cout<<"10";
			else if(a[2]=="C"&&b[2]=="A") cout<<"10";
			else if(a[2]=="B"&&b[2]=="C") cout<<"11";
			else if(a[2]=="D"&&b[2]=="F") cout<<"11";
			else if(a[2]=="B"&&b[2]=="A") cout<<"11";
			else if(a[2]=="C"&&b[2]=="B") cout<<"11";
			else if(a[2]=="F"&&b[2]=="D") cout<<"11";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
