#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int sum1,sum2;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<=s1.size()-1;i++){
		if(s1[i]>='A'&&s1[i]<='Z'){
			a=s1[i];
			break;
		}
		sum1=sum1*10+s1[i];
	}
	for(int i=0;i<=s2.size()-1;i++){
		if(s2[i]>='A'&&s2[i]<='Z'){
			b=s2[i];
			break;
		}
		sum2=sum2*10+s2[i];
	}
	if(sum1==sum2){
		cout<<"1";	
	}else{
		cout<<"000";
		return 0;
	}
	if(a>='A'&&a<='C'&&b>='A'&&b<='C'||a>='D'&&a<='F'&&b>='D'&&b<='F'){
		cout<<"1";
		if(abs(a-b)==1){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"00";
	}
	return 0;
} 
