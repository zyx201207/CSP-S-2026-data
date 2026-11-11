#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1;
	string s1;
	string c2;
	string s2;
	cin>>c1>>s1>>c2>>s2;
	
	int a=0;
	int b=0;
	int c=0;
	int d=0; 
	
	if(c1==c2){
		a=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			b=1;
			if((s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))||
			   (s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||
			   (s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B'))||
			   (s1[2]=='D'&&s2[2]=='F')||
			   (s1[2]=='F'&&s2[2]=='D')){
				c=1;
				if((int(s1[2])+1==int(s2[2]))||
				   (int(s1[2])-1==int(s2[2]))){
					d=1;
				}
			}
		}
	}

	cout<<a<<b<<c<<d;	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
