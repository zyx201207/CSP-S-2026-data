#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>c>>b>>d;
	if(a[0]==b[0]){
		if(a[1]==b[1]){
			cout<<"1";
		}else{
		cout<<"0000";
		return 0;
	} 
	
	}else{
		cout<<"0000";
		return 0;
	} 
	int f=0;
	if(c[0]==d[0]){
		if(c[1]==d[1]){
		
			cout<<1;
			f=1;
		}else{
			cout<<0;
		}
		
    }else{
    	cout<<0;
	}
    int h=0;
    if(c[2]=='A' || c[2]=='B' || c[2]=='C'){
    	if(d[2]=='A' || d[2]=='B' || d[2]=='C'){
    			if(f==1){
    				cout<<1;
				}else{
					cout<<0;
				}		
			}
			else{
				cout<<0;
			}
		}
	if(c[2]=='D' || c[2]=='E'){
		if(d[2]=='E' || d[2]=='D'){
				if(f==1){
					cout<<1;
				}else{
					
					cout<<0;
				}
		}
		else{
			cout<<0;
			
		}
	}
	for(int i=0;i<=1;i++){
		if(f==1 && c[2]=='A'){
			if(d[2]=='B'){
				
				cout<<1;
				break;
			}
			else{
				cout<<0;
				break;
			}
		}
		if(f==1 && c[2]=='B'){
			if(d[2]=='A' || d[2]=='C'){
				cout<<1;
				break;
			}
			else{
				cout<<0;
				break;
			}
		}
		if(f==1 && c[2]=='C'){
			if(d[2]=='B'){
				cout<<1;
				break;
			}
			else{
				cout<<0;
				break;
			}
		}
		if(f==1 && c[2]=='D'){
			if(d[2]=='E'){
				cout<<1;
				break;
			}else{
				cout<<0;
				break;
			}
		}
		if(f==1 && c[2]=='E'){
			if(d[2]=='D'){
				cout<<1;
				break;
			}else{
				cout<<0;
				break;
			}
		}
		cout<<0;
		break;
	}
	return 0; 
	
}
