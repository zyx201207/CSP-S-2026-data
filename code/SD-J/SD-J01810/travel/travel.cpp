#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ca,cb,sa,sb;
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	if(sa[0]==sb[0]&&sa[1]==sb[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	
	if(sa[2]=='A'||sa[2]=='B'||sa[2]=='C'){
		if(sb[2]=='A'||sb[2]=='B'||sb[2]=='C'){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else{
		if(sb[2]=='F'||sb[2]=='D'){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	
	
	if(sa[2]=='D'){
		if(sb[2]=='F'){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(sa[2]=='F'){
		if(sb[2]=='D'){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	
	
	if(sa[2]+1==sb[2]||sa[2]-1==sb[2]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	return 0;
}
