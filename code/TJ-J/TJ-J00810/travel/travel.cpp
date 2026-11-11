#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,x,y;
	cin>>a>>b>>x>>y;
	if(a==x){
		if(b[0]+b[1]==y[0]+y[1]){
			if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(y[2]=='A'||y[2]=='B'||y[2]=='C'))||(b[2]=='D'||b[2]=='F')&&(b[2]=='D'||b[2]=='F')){
				if((b[2]=='A'&&y[2]=='B')||(b[2]=='B'&&y[2]=='A')){
					cout<<"1111";
				}
				else if((b[2]=='B'&&y[2]=='C')||(b[2]=='C'&&y[2]=='B')){
					cout<<"1111";
				}
				else if((b[2]=='D'&&y[2]=='F')||(b[2]=='F'&&y[2]=='D')){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
