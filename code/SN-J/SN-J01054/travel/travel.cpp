#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b;
	string d;

	cin>>a;
	cin>>b;
	cin>>c>>d;

	if(a==c){
		if(a==01||a==16){
			cout<<'0'<<'0'<<'0'<<'0';
		}
		else{
			cout<<'1';
			if(b[0]==d[0]&&b[1]==d[1]){
				cout<<1;
				
				if(b[2]+1==d[2]){
					if(b[2]=='C')cout<<'0'<<'0';
					else cout<<'1'<<'1';
		
				}
				else if(b[2]-1==d[2]){
					if(b[2]=='D')cout<<'0'<<'0';
					else cout<<'1'<<'1';
		
				}
				else if(b[2]+2==d[2]){
					if(b[2]=='A')cout<<'1';
					else cout<<'0'<<'0';
		
				}
				else if(b[2]-2==d[2]){
					if(b[2]=='C')cout<<'1';
					else cout<<'0'<<'0';
		
				}
				else{
					cout<<'0'<<'0';
				}
		
			}
			else{
				cout<<'0'<<'0','0';
			}
		}
		
	}
	else{
		cout<<'0'<<'0'<<'0'<<'0';
	}
	
	return 0;
	
}
 
