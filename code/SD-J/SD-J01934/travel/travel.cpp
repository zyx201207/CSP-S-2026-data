#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[10];
	char s1[10];
	char c2[10];
	char s2[10];
	string a;
	char b[10];
	char c[10];
	char d[10];
	char e[10];
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	if(c1[0]==c2[0]){
		a+="1";	
	}
	else{
		a+="0";
	}
	for(int i=0;i<3;i++){
		if(s1[i]-'0'>=0 && s1[i]-'0'<=9){
			b[i]=s1[i];
		}
		else{
			d[i]=s1[i];
		}
		if(s2[i]-'0'>=0 && s2[i]-'0'<=9){
			c[i]=s2[i];
		}
		else{
			e[i]=s2[i];
		}	
	}
	if(b[0]==c[0] && b[1]==c[1]){
		a+="1";
	}
	else{
		a+="0";
	}
	if(d[0]-'A'<=2 && e[0]-'A'<=2){
		a+="1";
	}
	else if(d[0]-'A'>2 && e[0]-'A'>2){
		a+="1";
	}
	else{
		a+="0";
	}
	if((d[0]-'A')-(e[0]-'A')==1 || (e[0]-'A')-(d[0]-'A')==1){
		a+="1";
	}
	else{
		a+="0";
	}
	cout<<a;
	return 0;
}
