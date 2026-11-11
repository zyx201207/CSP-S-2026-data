#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1=0,a2=0;
	string b1,b2;
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(b1[0]==b2[0] and b1[1]==b2[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if((b1[2]=='D' and b2[2]=='F') or (b1[2]=='F' and b2[2]=='D') or(b1[2]!='D' and b1[2]!='F' and b2[2]!='F' and b2[2]!='D')){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if((b1[2]+1==b2[2]+0 or b1[2]-1==b2[2]+0)){
		cout<<1;
	}else{
		cout<<0;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
} 
