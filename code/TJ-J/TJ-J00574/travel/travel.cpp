#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		bool z=false;
		bool c=false;
		bool d=false;
		for(int i=0;i<s1.size();i++){
			if('A'<=s1[i]&&s1[i]<='Z'){
				a=s1[i]-'A'+1;
			}
		}
		for(int i=0;i<s2.size();i++){
			if('A'<=s2[i]&&s2[i]<='Z'){
				b=s2[i]-'A'+1;
			}
		}
		for(int i=0;i<s1.size();i++){
			for(int j=0;j<s2.size();j++){
				if(s1[0]==s2[0]&&s1[1]==s2[1]){
					z=true;
					break;
				}
			}
			if(z==true){
				break;
			}
		}
		
		for(int i=0;i<s1.size();i++){
			for(int j=0;j<s2.size();j++){
				if((z==true)&&((1<=a&&a<=3&&1<=b&&b<=3)||(4<=a&&a<=5&&4<=b&&b<=5))){
					c=true;
					break;
				}
			}
			if(c==true){
				break;
			}
		}
		for(int i=0;i<s1.size();i++){
			for(int j=0;j<s2.size();j++){
				if(c==true&&((a==1&&b==2)||(a==2&&b==1)||(a==2&&b==3)||(a==3&&b==2)||(a==4&&b==5)||(a==5&&b==4))){
					d=true;
					break;
				}			
			}
		}
		if(z==true){
			cout<<1;
		}
		else{
			cout<<0;
		}
		if(c==true){
			cout<<1;
		}
		else{
			cout<<0;
		}
		if(d==true){
			cout<<1;
		}
		else{
			cout<<0;
		}		
	}
	else{
		cout<<0<<0<<0<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
