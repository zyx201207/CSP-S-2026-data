#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool pa=0,pb=0;
	string aa,ba,ab,bb;
	cin>>aa>>ba>>ab>>bb;
	if(aa!=ab){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(ba[0]!=bb[0] || ba[1]!=bb[1]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(ba[2]=='D' || ba[2]=='E'){
		pa=1;
	}
	if(bb[2]=='D' || bb[2]=='E'){
		pb=1;
	}
	if(pb!=pa){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(ba[2]=='A' && bb[2]=='C'){
		cout<<0;
		return 0;
	}
	if(bb[2]=='A' && ba[2]=='C'){
		cout<<0;
		return 0;
	}
	cout<<1;
	return 0;
} 
