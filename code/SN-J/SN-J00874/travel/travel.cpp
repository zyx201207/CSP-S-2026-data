#include<bits/stdc++.h>
using namespace std;

char s1,s2,s3,s4,s5,s6;
int c1,c2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=0;
	cin>>c1>>s1>>s2>>s3>>c2>>s4>>s5>>s6;
	if(c1==c2){
		
		cout<<"1";
		
		if(s1==s4){
			if(s2==s5){
				cout<<"1";
				if(s3=='A'){
					if(s6=='A'){cout<<"1";a=1;}
					if(s6=='B'){cout<<"1";a=1;}
					if(s6=='C'){cout<<"1";a=1;}
				}
				if(s3=='B'){
					if(s6=='A'){cout<<"1";a=1;}
					if(s6=='B'){cout<<"1";a=1;}
					if(s6=='C'){cout<<"1";a=1;}
				}
				if(s3=='C'){
					if(s6=='A'){cout<<"1";a=1;}
					if(s6=='B'){cout<<"1";a=1;}
					if(s6=='C'){cout<<"1";a=1;}
				}if(s3=='D'){
					if(s6=='D'){cout<<"1";a=1;}
					if(s6=='F'){cout<<"1";a=1;}
				}
				if(s3=='F'){
					if(s6=='D'){cout<<"1";a=1;}
					if(s6=='F'){cout<<"1";a=1;}
				}
				if(a==0){
					cout<<"00";
				}else{
					if(a==2){
						cout<<"1";
					}
					if(a==1){
						
						if(s3=='A'&&s6=='B') {cout<<"1";a=9;}
						if(s3=='B'&&s6=='A') {cout<<"1";a=9;}
						if(s3=='C'&&s6=='B') {cout<<"1";a=9;}
						if(a==1){
							cout<<"0";
						}
					}
				}
				
			}else{
				cout<<"000";
			}
		}else{
			cout<<"000";
		}
		
	}else{
		cout<<"0000";
	}
	
	/*cout<<c1<<" ";
	cout<<c2<<" ";
	cout<<s1<<" ";
	cout<<s2<<" ";
	cout<<s3<<" ";
	cout<<s4<<" ";
	cout<<s5<<" ";
	cout<<s6<<" ";*/
	return 0;
}
