#include<bits/stdc++.h>
using namespace std;
	int c1,c2;
	char  s1[4], s2[4],a[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[0]='1';

	}
	else{
		a[1]='0';
	}
	
	if(a[0]=='1'&&s1[0]==s2[0]&&s1[1]==s2[1]){
		a[1]='1';
	}
	else{
		a[1]='0';
	}
	
	
	if(a[1]=='1'&&(((int(s1[2])<=67&&int(s1[2])>=65)&&(int(s2[2])<=67&&int(s2[2])>=65))||((int(s1[2])<=69&&int(s1[2])>=68)&&(int(s2[2])<=69&&int(s2[2])>=68)))){
		a[2]='1';
	}
	else{
		a[2]='0';
	}
	
	if(a[2]=='1'){
		if(int(s1[2])>int(s2[2])){
			if((int(s1[2])-1)==int(s2[2])){
				a[3]='1';	
			}
			else{
				a[3]='0';
			}
		}
		else{
			if((int(s2[2])-1)==int(s1[2])){
				a[3]='1';	
			}
			else{
				a[3]='0';
			}
		}
	}
	else{
		a[3]='0';
	}
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	return 0;
}