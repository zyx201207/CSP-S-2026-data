#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string ap,bp;
	cin>>a>>ap>>b>>bp;
	if(char(a)==char(b)){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	if(ap[0]==bp[0] && ap[1]==bp[1]){
		cout<<"1";
		if(ap[2]!=char(68) && ap[2]!=char(69) && bp[2]==char(68) || bp[2]==char(69)){
			cout<<"0"<<"0";
			return 0;
		}
		else{
			cout<<"1";
			if(char(ap[2])-char(bp[2])==1 || char(ap[2])-char(bp[2])==-1){
				cout<<"1";
				return 0;
			}
			else{
				cout<<"0";
				return 0;
			}
		}
		
	}
	else{
		cout<<"0"<<"0"<<"0";
		return 0;
	}
	return 0;
} 
