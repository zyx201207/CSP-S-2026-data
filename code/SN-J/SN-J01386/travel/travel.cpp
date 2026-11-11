#include<bits/stdc++.h>
using namespace std;
string s,s1,t,t1;
int sum,ans,cnt,now;
char a,b;
bool vis=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>t>>t1;
	if(s==t){
		cout<<1;
		for(int i=0;i<s1.size();i++){
			if(s1[i]>='0'&&s1[i]<='9'){
				sum=sum*10+(s1[i]-'0');
			}else{
				a=s1[i]; 
			}
		}
		for(int i=0;i<t1.size();i++){
			if(t1[i]>='0'&&t1[i]<='9'){
				ans=ans*10+(t1[i]-'0');
			}else{
				b=t1[i];
			}
		}
		if(sum==ans){
			cout<<1;
			if((a>'C'&&b>'C')||(a<='C'&&b<='C')){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<"00";
		}
		if(abs(sum-ans)==1){
			cnt++;
		}
		if(abs(a-b)==1){
			now++;
		}
		if((a!='C'&&b!='D')||(a!='C'&&b!='D')){
			vis=true;
		}
		if(now+cnt==1&&vis==true){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}else{
		cout<<"0000";
	}
} 
