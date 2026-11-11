#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1, s1, c2, s2;
	cin>>c1>>s1>>c2>>s2;
	
    if(c1[1]==c2[1]&&c1[2]==c2[2]){
    	cout<<'1';
	}	else{
		cout<<'0';
	
	}
	for(int i=0;i<1;i++){
	if(s1[i]==s2[i]&&s1[i+1]==s2[i+1]){
    	cout<<'1';}
		else{
		cout<<'0';
	}
	}
	
	if(s1[3]=='D'||s1[3]=='F'){
		if(s2[3]=='F'||s2[3]=='D'){
		cout<<'1';
		}else{
			cout<<'0';
		}}
    else if(s1[2]<='C'){
    	if(s2[2]<='C'){
    		cout<<'1';
		}else{
			cout<<'0';
		}}
		else{
		cout<<'0';
	}
	
	if(s1[2]=='D'||s1[2]=='F'){
		if(s2[2]=='F'||s2[2]=='D'){
		cout<<'1';
		}
		else{
		cout<<'0';
	}}
    else if(s1[2]=='A'){
    	if(s2[2]=='B'){
    		cout<<'1';
		}
		else{
		cout<<'0';
	}}
	else if(s1[2]=='B'){
    	if(s2[2]=='A'||s2[2]=='C'){
    		cout<<'1';
		}
		else{
		cout<<'0';
	}}
	else if(s1[2]=='C'){
    	if(s2[2]=='B'){
    		cout<<'1';
		}
		else{
		cout<<'0';}
	}
	
	
	
	
	

	
	return 0;
}
