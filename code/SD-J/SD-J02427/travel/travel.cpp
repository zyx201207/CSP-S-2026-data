#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	int x=0,s=0;
	cin>>c1>>s1>>c2>>s2;
	int l=c1.size();
	int l1=s1.size();
	for(int i=1;i<=l;i++){
		if(c1[i]==c2[i])  x++;
	}
	if(x==l) {
		cout<<"1";
		for(int i=1;i<=l1;i++){
			if(s1[i]==s2[i])  s++;
		}
		if(s>=2) {
		cout<<"1";
		if(s1[l1-1]=='A'){
			if( s2[l1-1]=='c')  cout<<"10";
			else if(s2[l1-1]=='B') cout<<"11";
			else{
				cout<<"00";
			}
		}
		else if(s1[l1-1]=='B'){
			if(s2[l1-1]=='A' or s2[l1-1]=='C')  cout<<"11";
			else{
				cout<<"00";
			}
		}
		else if(s1[l1-1]=='C'){
			if(s2[l1-1]=='A')  cout<<"10";
			else if(s2[l1-1]=='B') cout<<"11";
			else{
				cout<<"00";
			}
		}
		else if(s1[l1-1]=='D'){
			if(s2[l1-1]=='F') {
			cout<<"11";
		}
			else{
				cout<<"00";
			}
		}
			else if(s1[l1-1]=='F'){
			if(s2[l1-1]=='D') cout<<"11";
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
	}
} 

