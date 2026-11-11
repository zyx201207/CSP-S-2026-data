#include<bits/stdc++.h>
using namespace std;
int fl1,fl2,fl3;
char s1[4],s2[4],s3[4],s4[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1+1>>s2+1>>s3+1>>s4+1;
	if(s1[1]==s3[1]&&s1[2]==s3[2]){
		fl1=1;
		cout<<1;
	}else{
		cout<<0;
	}if(s2[1]==s4[1]&&s2[2]==s4[2]&&fl1){
		cout<<1;
		fl2=1;
	}else{
		cout<<0;
	}if(fl2==1&&((s2[3]<'D'&&s4[3]<'D')||(s2[3]>'C'&&s4[3]>'C'))){
		cout<<1;
		fl3=1;
	}else{
		cout<<0;
	}if(fl3==1){
		if(s2[3]<'D'){
			if(abs(s2[3]-s4[3])==1){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			if((s2[3]=='D'&&s4[3]=='F')||(s2[3]=='F'&&s4[3]=='D')){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else{
		cout<<0;
	}
	return 0;
}
