#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[2],c2[2],s1[3],s2[3];
	cin>>c1[2]>>s1[3]>>c2[2]>>s2[3];
	if(c2[2]-c1[2]==-2){
		cout<<0;
	}
	else{
		cout<<1;
	}
	if(s2[3]-s1[3]==5||s2[3]-s1[3]==-5){
		cout<<0;
	}
	else{
		cout<<1;
	}
	if(s2[3]-s1[3]==3||s2[3]-s1[3]==-3){
		cout<<0;
	}
	else{
		cout<<1;
	}
	if(s2[3]-s1[3]==1||s2[3]-s1[3]==-1){
		cout<<0;
	}
	else{
		cout<<1;
	}
		return 0;
}
