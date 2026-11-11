#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool op1=false,op2=true,op3=false,op4=false;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		op1=true;
		for(int i=0;i<s1.size()-1;i++){
			if(s1[i]!=s2[i]){
				op2=false;
			}
		}
		if(op2){
			if(s1[s1.size()-1]=='A'){
				if(s2[s2.size()-1]=='A'||s2[s2.size()-1]=='B'||s2[s2.size()-1]=='C'){
					op3=true;
				}
			}else if(s1[s1.size()-1]=='B'){
				if(s2[s2.size()-1]=='A'||s2[s2.size()-1]=='B'||s2[s2.size()-1]=='C'){
					op3=true;
				}
			}else if(s1[s1.size()-1]=='C'){
				if(s2[s2.size()-1]=='A'||s2[s2.size()-1]=='B'||s2[s2.size()-1]=='C'){
					op3=true;
				}
			}else if(s1[s1.size()-1]=='D'){
				if(s2[s2.size()-1]=='F'){
					op3=true;
				}
			}else if(s1[s1.size()-1]=='F'){
				if(s2[s2.size()-1]=='D'){
					op3=true;
				}
			}
			if(op3){
				if(s1[s1.size()-1]=='A'){
					if(s2[s2.size()-1]=='B'){
						op4=true;
					}
				}else if(s1[s1.size()-1]=='B'){
					if(s2[s2.size()-1]=='A'||s2[s2.size()-1]=='C'){
						op4=true;
					}
				}else if(s1[s1.size()-1]=='C'){
					if(s2[s2.size()-1]=='B'||s2[s2.size()-1]=='D'){
						op4=true;
					}
				}else if(s1[s1.size()-1]=='D'){
					if(s2[s2.size()-1]=='C'||s2[s2.size()-1]=='F'){
						op4=true;
					}
				}else if(s1[s1.size()-1]=='F'){
					if(s2[s2.size()-1]=='D'){
						op4=true;
					}
				} 
			} 
		}
	}
	if(op1==true){
		cout<<1;
	}else{
		cout<<0;
	}
	if(op2==true&&op1==true){
		cout<<1;
	}else{
		cout<<0;
	}
	if(op3==true){
		cout<<1;
	}else{
		cout<<0;
	}
	if(op4==true){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
