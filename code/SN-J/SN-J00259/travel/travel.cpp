#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,c=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	for(int i=0;i<2;i++){
		if(s1[i]==s2[i]){
			c++;
		}
	}
	if(c==2){
		cout<<1;
	}else{
		cout<<0;
	}
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F')){
		cout<<0;
	}else{
		cout<<1;
	}
	if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
		cout<<1;
	}else{
		cout<<0;
	}
	//cout<<s1[2]-s2[2];
	return 0;
} 
