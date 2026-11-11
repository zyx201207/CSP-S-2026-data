#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	char x=b[2],y=d[2];
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			if(x=='A'){
				if(y=='B'){
					cout<<11;
				}
				else if(y=='C'){
					cout<<10;
				}
				else{
					cout<<0<<0;
				}
			}
			else if(x=='B'){
				if(y=='A'||y=='C'){
					cout<<11;
				}
				else{
					cout<<0<<0;
				}
			}
			else if(x=='C'){
				if(y=='B'){
					cout<<11;
				}
				else if(y=='A'){
					cout<<10;
				}
				else{
					cout<<0<<0;
				}
			}
			else if(x=='D'){
				if(y=='F'){
					cout<<11;
				}
				else{
					cout<<0<<0;
				}
			}
			else if(x=='F'){
				if(y=='D'){
					cout<<11;
				}
				else{
					cout<<0<<0;
				}
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	return 0;
} 
