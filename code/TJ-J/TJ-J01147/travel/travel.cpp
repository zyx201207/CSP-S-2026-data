#include<bits/stdc++.h>
using namespace std;
char a[5],b[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c="00000";
	string n,m;
	cin >> n;
	for(int i=1;i<=3;i++){
		cin >> a[i];
	}
	cin >> m;
	if(n==m)c[1]='1';
	else c[1]='0';
	bool ft=true;
	for(int i=1;i<=3;i++){
		cin >> b[i];
		if(c[1]=='1'){
			if(i==1||i==2){
				if(a[i]!=b[i])ft=false;
			}else if(i==3&&ft!=false){
				if((a[3]=='A'&&b[3]=='C')||(b[3]=='A'&&a[3]=='C')){
					c[4]='0';
				}else{
					c[4]='1';
				}
				if((a[3]=='A'||a[3]=='B'||a[3]=='C')&&(b[3]=='D'||b[3]=='F')){
					c[3]='0';
					c[4]='0';
				}else if((b[3]=='A'|b[3]=='B'||b[3]=='C')&&(a[3]=='D'||a[3]=='F')){
					c[3]='0';
					c[4]='0';
				}else {
					c[3]='1';
				}
			}else{
				c[3]='0';
				c[4]='0';
			}
	
		if(ft)c[2]='1';
		else c[2]='0';
		}else{
			c[2]='0';
			c[3]='0';
			c[4]='0';	
			}
	}
	for(int i=1;i<=4;i++){
		cout << c[i];
	}
	return 0;
} 
