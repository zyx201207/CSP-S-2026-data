#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in",'r',stdin);
freopen("travel.out",'w',stdout);
	char c1[4],s1[5],c2[4],s2[5];
	cin>>c1[1]>>c1[2];
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	cin>>c2[1]>>s2[2];
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	cout<<"1";
	if(s1[1]==s2[1]&&s1[2]==s2[2]){
		cout<<"1";
		if((s1[3]<='C'&&s2[3]<='C')||(s1[3]>='D'&&s2[3]>='D')){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"0";
	}
	if((s1[3]-s2[3]==1)||(s2[3]-s1[3]==1)){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
