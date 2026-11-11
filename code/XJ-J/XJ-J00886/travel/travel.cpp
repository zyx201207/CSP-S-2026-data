#include<iostream>
#include<cstdio>
 using namespace std;
 int main(){
 	freopen("travel.in","r",stdin);
 	freopen("travel.ans","w",stdout);
 	int a,b;
	string as;
	string bs;
 	cin>>a>>as>>b>>bs;
 	if(a!=1&&a!=16&&b!=1&&b!=16){
 		if(a==b){
 			cout<<1;
			if(as[0]*10+as[1]==bs[0]*10+bs[1]){
				cout<<1;
			}
			else{
				cout<<"000";
				return 0;
				}
			if(as[2]=='A'||as[2]=='B'||as[2]=='C'){
				if(bs[2]=='A'||bs[2]=='B'||bs[2]=='C'){
					cout<<1;
			}
				else{
					cout<<"00";
					return 0;
				}
			}
			else if(as[2]=='D'||as[2]=='F'){
				if(bs[2]=='D'||bs[2]=='F'){
					cout<<1;
		}
				else{
					cout<<"00";
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
			if(as[2]=='A'){
				if(bs[2]=='B'){
					cout<<1;
				}
				else {
					cout<<0;
				} 
			}
			else if(as[2]=='B'){
				if(bs[2]=='A'||bs[2]=='C'){
					cout<<1;
				}
				else {
					cout<<0;
				} 
			}
			else if(as[2]=='C'){
				if(bs[2]=='B'){
					cout<<1;
				}
				else {
					cout<<0;
				} 
			}
			else if(as[2]=='D'){
				if(bs[2]=='F'){
					cout<<1;
				}
				else {
					cout<<0;
				} 
			}
			
		}
		else{
			cout<<"0000";
			
			return 0;
		}
	}
		else{
			cout<<"0000";
			cout<<23;
			return 0;
			}



 	return 0;
 }
