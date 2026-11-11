#include<bits/stdc++.h>
using namespace std;
int c1,c2,ans[5];
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]=1;
		int i=0;
		char num1=s1[0],num2=s2[0];
		ans[1]=1;
		while(num1<='9'&&num1>='0'){
			if(num1!=num2)ans[1]=0;
			i++;
			num1=s1[i],num2=s2[i];
		}
		if(ans[1]==1){
			if(!(num1=='C'&&num2=='D')&&!(num1=='D'&&num2=='C')){
				ans[2]=1;
				if(abs(int(num1)-int(num2))==1){
					ans[3]=1;
				}
			}
		}
		for(int i=0;i<4;i++)cout<<ans[i];
	}
	else{
		for(int i=0;i<4;i++)cout<<ans[i]; 
	}
	return 0;
}
