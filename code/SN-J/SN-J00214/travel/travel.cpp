#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a;
	string b;
	string c;
	string d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1<<" ";
	}
	else{
		cout<<0<<" ";
	}
	if (a==c){	
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1<<" ";
		}
		else{
			cout<<0<<" ";
		}
	}
	else{
		cout<<0<<" ";
	}
	
	if(a==c){
	
		if(b[0]==d[0]&&b[1]==d[1]){
			
			if(b[2]=='D'||b[2]=='F'){		
			    if(d[2]=='D'||d[2]=='F'){
					cout<<1<<" ";
				}
				else{
					cout<<0<<" ";
				}
			}
			else if(b[2]!='D'&&b[2]!='F'){
				if(d[2]!='D'&&d[2]!='F'){
					cout<<1<<" ";
				}
				else{
					cout<<0<<" ";
				}
			}
			else{
				cout<<0<<" ";
			}
			
		}
		else{
			cout<<0<<" ";
		}
	}
	else{
		cout<<0<<" ";
	}
	
	if(a==c){
	
		if(b[0]==d[0]&&b[1]==d[1]){
			
			if(b[2]=='D'||b[2]=='F'){		
			    if(d[2]=='D'||d[2]=='F'){
					if(abs(b[2]-d[2])==2){
						cout<<1<<" ";
					}
					else{
						cout<<0<<" ";
					}
				}
				else{
					cout<<0<<" ";
				}
			}
			else if(b[2]!='D'&&b[2]!='F'){
				if(d[2]!='D'&&d[2]!='F'){
					if(abs(b[2]-d[2])==1){
						cout<<1<<" ";
					}
					else{
						cout<<0<<" ";
					}
				}
				else{
					cout<<0<<" ";
				}
			}
			else{
				cout<<0<<" ";
			}
			
		}
		else{
			cout<<0<<" ";
		}
	}
	else{
		cout<<0<<" ";
	}
	return 0;
}
	
