#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int aa, ba; 
	string ab, bb;
	cin>>aa>>ab>>ba>>bb;
	int is1, is2, is3, is4;
	if(aa==ba){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(ab[0]==bb[0] && ab[1]==bb[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	};
  	if((ab[2]=='D' && bb[2]=='F')){
  		cout<<"1";
	}
	else if((ab[2]=='F' && bb[2]=='D')){
		cout<<"1";
	}
	else if(ab[2]=='D' || bb[2]=='F' || ab[2]=='F' || bb[2]=='D'){
		cout<<"00";
		return 0;
	}
	else{
		cout<<"1";
	}
	
	if(abs(int(ab[2])-int(bb[2]))==1){
		cout<<"1";
	}
	else{
		cout<<"0";
		return 0;
	}
	return 0;
} 
