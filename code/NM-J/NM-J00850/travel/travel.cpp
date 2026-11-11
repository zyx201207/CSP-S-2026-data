#include<bits/stdc++.h>
using namespace std;
string a;
string a1;
string b;
string b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	if(a1[0]==b1[0] && a1[1]==b1[1]){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}
	if((a1[2]=='D' && b1[2]=='C') || (a1[2]=='C' && b1[2]=='D')){
		cout<<"00";
		return 0;
	}else{
		cout<<'1';
	}
	if(a1[2]>b1[2]){
		if(a1[2]-b1[2]==1){
			cout<<'1';
		}else{
			cout<<'0';
		}
	}else{
		if(b1[2]-a1[2]==1){
			cout<<'1';
		}else{
			cout<<'0';
		}
	}
	return 0;
}
