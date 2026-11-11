#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=c1.size();
	int b=s1.size();
	int c=c2.size();
	int d=s2.size();
	for(int i=0;i<a;i++){
			if(c1==c2){
				cout<<1;
				break;
				
			}else{
				cout<<0;
				break;
			}
	}
	for(int i=0;i<a;i++){
		if(s1[1]/100%10==s2[1]/100%10){
			if(s1[2]/10%10==s2[2]/10%10)
			cout<<1;			
			break;
			}else{
				cout<<0;
				break;
			}
	}
	for(int i=0;i<a;i++){
		if(s1[3]=='A'&&s2[3]=='B'||s1[3]=='A'&&s2[3]=='C'||s1[3]=='B'&&s2[3]=='A'||s1[3]=='B'&&s2[3]=='C'||s1[3]=='C'&&s2[3]=='A'||s1[3]=='C'&&s2[3]=='B'){
			cout<<1;
			break;
		}else if(s1[3]=='D'&&s2[3]=='F'||s1[3]=='F'&&s2[3]=='D'){
			cout<<1;
			break;
		}else{
			cout<<0;
			break;
		}
	}
	for(int i=0;i<a;i++){
		if(s1[3]=='A'&&s2[3]=='B'||s1[3]=='B'&&s2[3]=='A'||s1[3]=='B'&&s2[3]=='C'||s1[3]=='C'&&s2[3]=='B'||s1[3]=='D'&&s2[3]=='F'||s1[3]=='F'&&s2[3]=='D'){
			cout<<1;
			break;
		}else{
			cout<<0;
			break;
		}
	}		
 
	return 0;
} 
