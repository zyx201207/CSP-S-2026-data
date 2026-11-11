#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	bool a[4]={0};
	if(s1==s3){
		a[1]=1;
		if(s2[1]==s4[1]){
			a[2]=1;
			if(s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C'||s2[2]>='D'&&s2[2]<='F'&&s4[2]>='D'&&s4[2]<='F'){
				a[3]=1;
				if(s2[2]-s4[2]==1||s4[2]-s2[2]==1){
					a[4]=1;
				}
			}	
		}
	}
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
} 
