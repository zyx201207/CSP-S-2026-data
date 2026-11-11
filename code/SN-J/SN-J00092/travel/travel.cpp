#include<bits/stdc++.h>
using namespace std;
string c1,c2;
int a1,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	c1[0]=s1[2];
	c2[0]=s2[2];
	for(int i=0;i<=s1.size();i++){
		if(s1[i]>='0' && s1[i]<='9'){
			a1=a1*10+s1[i];
		}
	}
	for(int i=0;i<=s2.size();i++){
		if(s2[i]>='0' && s2[i]<='9'){
			a2=a2*10+s2[i];
		}
	}
	if(a1==a2){
		cout<<1;
		if((c2[0]<='C' && c1[0]<='C') || (c2[0]>='D' && c1[0]>='D')){
			cout<<1;
		}
		else{
			cout<<0; 
		}
	}
	else{
		cout<<0;
		cout<<0;
	}
	if(a1==a2){
		if((c1[0]-'0'+1==c2[0]-'0' && c1[0]!='C') || (c1[0]-'0'-1==c2[0]-'0' && c1[0]!='D')){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
