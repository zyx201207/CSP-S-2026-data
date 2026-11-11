#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s,j1,j;
	cin>>s1>>s>>j1>>j;
	if(s1!=j1){
		cout<<"0000";
		return 0;
	}else{
		for(int i=0;i<=1;i++){
			if(s[i]!=j[i]){
				cout<<1000;
				return 0;
			}
		}
		if(s[2]<='C'&&j[2]<='C' || s[2]>='D'&&j[2]>='D'){
			if(char(s[2]-1)!=j[2] && char(s[2]+1)!=j[2]){
				cout<<1110;
				return 0;
			}else{
				cout<<1111;
				return 0;
			}
		}else{
			cout<<1100;
			return 0;
		}
	}
	return 0;
}
