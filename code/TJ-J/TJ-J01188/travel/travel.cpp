#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ca;
	int cb; 
	string sa;
	string sb;
	cin >> ca >> sa >> cb >> sb;
	int nun =0;
	if(ca==cb){
		cout << "1";
	}
	else{
		for(int i =1;i<=4;i++){
			cout << "0";
		}
		return 0;
	}
	for(int i=0;i<2;i++){
		if(sa[i]==sb[i]){
			nun++;
		}
	}
	if(nun==2){
		cout <<"1";
		
	}
	else {
	    cout << "0";
	}
	if(sa[2]=='A'||sa[2]=='B'||sa[2]=='C'){
		if(sb[2]=='A'||sa[2]=='B'||sa[2]=='C'){
			cout <<"1";
		}
		else{
			cout << "0" <<"0";
			return 0;
		}
	}
	if(sa[2]=='D'||sa[2]=='F'){
		if(sb[2]=='D'||sb[2]=='F'){
			cout <<"1";
		}
		else{
			cout << "0"<<"0";
			return 0;
		}
	}
	if(sa[2]=='A'||sa[2]=='C'){
		if(sb[2]=='B'){
			cout <<"1";
		}
		else cout <<"0";
	}
	if(sa[2]=='B'){
		if(sb[2]=='A'||sb[2]=='C'){
			cout <<"1";
		}
		else cout <<"0";
	}
    if(sa[2]=='D'){
		if(sb[2]=='F'){
			cout <<"1";
		}
		else cout <<"0";
	}
	if(sa[2]=='F'){
		if(sb[2]=='D'){
			cout <<"1";
		}
		else cout <<"0";
	}
	return 0;
}
