#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;//a=c1,b=s1,c=c2,d=s2
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[1]==c[1]){
		cout<<"1";
		if(b[1]==d[1]){
			cout<<"1";
			if(b[2]>='A' && b[2]<='C'){
				if(d[2]>='A' && d[2]<='C'){//left
					cout<<"1";
					if(b[2]=='A' && d[2]=='B'){
						cout<<"1";//one
					}
					else if(b[2]=='B' && d[2]=='C'){
						cout<<"1";//two
					}
					else if(b[2]=='B' && d[2]=='A'){
						cout<<"1";//three
					}
					else if(b[2]=='C' && d[2]=='B'){
						cout<<"1";//four
					}	
					else{
						cout<<"0";
					}
				}
				else{
					cout<<"00";
				}
			}
			else if(b[2]>='D' && b[2]<='F'){
				if(d[2]>='D' && d[2]<='F'){
					cout<<"1";//right
					if(b[2]=='D' && d[2]=='F'){
						cout<<"1";
					}
					else if(b[2]=='F' && d[2]=='D'){
						cout<<"1";
					}
				}
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
		return 0;
	}
	return 0;
}