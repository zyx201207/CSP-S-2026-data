#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			if((e=='A'&&(f=='B'||f=='C'))||(e=='B'&&(f=='A'||f=='C'))||(e=='C'&&(f=='B'||f=='A'))){
				cout<<1;
				if(e=='A'&&(f=='B')||(e=='B'&&(f=='A')||(e=='C'&&(f=='B')))){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
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
