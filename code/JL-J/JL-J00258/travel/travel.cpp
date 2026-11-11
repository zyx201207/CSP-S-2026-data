#include<bits/stdc++.h>
using namespace std;
char a,b;

int main(){
freopen("travel.in","r",stdin);	
freopen("travel.out","w",stdout);	
string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
if(c1==c2){
	cout<<"1";
	}
else cout<<"0";	
if(s1==s2){
	cout<<"1"
	}
	else cout<<"0";
	if(s1=="A"||s1=="B"||s1=="C"&&s2=="A"||s2=="B"||s2=="C"){
		cout<<"1";
		}
		else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
