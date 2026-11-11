#include<bits/stdc++.h>
using namespace std;
char c1,c2;
string r,x;
string r1,x1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>r1>>x>>x1;
	c1=r1[2];
	c2=x1[2];
	if(r==x){
		cout<<"1";
		if(r1[0]==x1[0]&&r1[1]==x1[1]){
			cout<<"1";
			if(c1=='B'||c1=='A'||c1=='C'){
				if(c2=='B'||c2=='A'||c2=='C'){
					cout<<"1";
				if(c2=='B'&&c1=='A'){
					cout<<"1";	
				}
				else if(c2=='B'&&c1=='C'){
					cout<<"1";	
				}
				else if(c2=='A'&&c1=='B'){
					cout<<"1";	
				}
				else if(c2=='C'&&c1=='B'){
					cout<<"1";	
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else if(c1=='D'||c1=='F'){
			if(c2=='D'||c2=='F') cout<<"11";
			else{
				cout<<"00";
			}
		}
		
	}
	else{
		cout<<"000";
	}
}
else{
	cout<<"0000";
}
	return 0;
} 
