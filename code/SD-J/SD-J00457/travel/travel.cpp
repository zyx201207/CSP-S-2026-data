#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1a,c2a;
	int n1,n2,n3,n4;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	c1a=(c1[0]-'0')*10+c1[1]-'0';
	c2a=(c2[0]-'0')*10+c2[1]-'0';
	if(c1a==c2a&&c1a>1&&c1a<=17&&c1a&&!(c1a==16)){
		n1=1;
	}else{
		n1=0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&n1==1){
		n2=1;
	}else{
		n2=0;
	}
	
	int d1,f1;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		d1=1;
	}
	else{
		d1=0;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		f1=1;
	}
	else{
		f1=0;
	}
	if(d1==f1&&n2==1){
		n3=1;
	}else{
		n3=0;
	}
	if(s1[2]-s2[2]==1||s2[2]-s1[2]==1&&!(s1[2]=='D')&&!(s1[2]=='C')){
		if(n3==1){
			n4=1;
		}
		else{
			n4=0;
	}
	}
	else{
		n4=0;
	}
	cout<<n1<<n2<<n3<<n4;
	return 0;
}
