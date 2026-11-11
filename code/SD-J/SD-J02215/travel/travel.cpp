#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[5],s1[5],c2[5],s2[5];
	for(int i=1;i<=2;i++){
		cin>>c1[i];
	}for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	for(int i=1;i<=2;i++){
		cin>>c2[i];
	}for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	int flag=1;
	for(int i=1;i<=2;i++){
		if(c1[i]!=c2[i]){
			flag=0;
		}
	}
	if(flag==0){
		cout<<"0000";
		return 0;
	}else{
		cout<<flag;
	}
	flag=1;
	for(int i=1;i<=2;i++){
		if(s1[i]!=s2[i]){
			flag=0;
		}
	}
	if(flag==0){
		cout<<"000";
		return 0;
	}else{
		cout<<flag;
	}
	if((((s1[3]<='C'&&s1[3]>='A')&&(s2[3]<='C'&&s2[3]>='A'))||((s1[3]=='D'||s1[3]=='F')&&(s2[3]=='D'||s2[3]=='F')))){
		cout<<1;
	}else{
		cout<<0;
	}
	if((s1[3]==s2[3]+1)&&((s1[3]>='A'&&s1[3]<='C'&&s2[3]>='A'&&s2[3]<='C')||((s1[3]=='F'||s1[3]=='D')&&(s2[3]=='D'||s2[3]=='F')))||(s1[3]==s2[3]-1)&&((s1[3]>='A'&&s1[3]<='C'&&s2[3]>='A'&&s2[3]<='C')||((s1[3]=='F'||s1[3]=='D')&&(s2[3]=='D'||s2[3]=='F')))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
