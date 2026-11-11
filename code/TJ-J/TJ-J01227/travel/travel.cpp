#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool f1=false,f2=false,f3=false;
int main(){
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		for(int i=0;i<3;i++){
			if(s1[0]==s2[0]&&s1[1]==s2[1]){
				f1=true;
				if(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C')||s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')||s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
					f2=true;
					if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
						f3=true;
					}
				}
				
			}
		}
	}else{
		cout<<0;
	}
	if(f1==true){
		cout<<1;
	}else{
		cout<<0;
	}
	if(f2==true){
		cout<<1;
	}else{
		cout<<0;
	}
	if(f3==true){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
