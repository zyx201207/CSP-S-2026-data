#include<bits/stdc++.h>
using namespace std;
int c1,c2,s_1,s_2,bj;
string s1,s2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
		bj=1;
	}
	int k=10;
	for(int i=0;i<=1;i++){
		s_1+=(s1[i]-48)*k;
		s_2+=(s2[i]-48)*k;
		k/=10;
	}
	if(s_1==s_2&&bj==0){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&s_1==s_2&&bj==0){
		cout<<"1";
	}else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&s_1==s_2&&bj==0){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&abs(s1[2]-s2[2])==1&&s_1==s_2&&bj==0){
		cout<<"1";
	}else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&abs(s1[2]-s2[2]==1)&&s_1==s_2&&bj==0){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
