#include<bits/stdc++.h>
using namespace std;
string n,l,m,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>l>>m>>r;
	if(n!=m){
		cout<<"0000";
		return 0;
	}
	if(l[0]!=r[0] || l[1]!=r[1]){
		cout<<"1000";
		return 0;
	}
	if((l[2]>='D' && l[2]<='F') && (r[2]>='A' && r[2]<='C')){
		cout<<"1100";
		return 0;
	}
	if((r[2]>='D' && r[2]<='F') && (l[2]>='A' && l[2]<='C')){
		cout<<"1100";
		return 0;
	}
	if(l[2]=='D' && r[2]=='F'){
		cout<<"1111";
		return 0;
	}
	if(r[2]=='D' && l[2]=='F'){
		cout<<"1111";
		return 0;
	}
	if(abs(l[2]-r[2])==1){
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0;
}
