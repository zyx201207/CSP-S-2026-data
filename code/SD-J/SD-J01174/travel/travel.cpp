#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		char t1=s1[0]+s1[1],t2=s2[0]+s2[1];
		if(t1==t2){
			cout<<1;
			t1=s1[2],t2=s2[2];
			if((t1=='D'||t1=='F')&&(t2=='D'||t2=='F')){
				cout<<1;
				if((t1=='D'&&t2=='F')||(t1=='F'&&t2=='D')) cout<<1;
				else cout<<0;
			}
			else if((t1=='A'||t1=='B'||t1=='C')&&(t2=='A'||t2=='B'||t2=='C')){
				cout<<1;
				if(abs(t1-t2)==1) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
