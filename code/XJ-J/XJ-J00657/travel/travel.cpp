#include<bits/stdc++.h>
using namespace std;
string aa1,bb1,aa2,bb2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>aa1>>bb1>>aa2>>bb2;
	if(aa1==aa2){
		string s1="";
		string s2="";
		s1=bb1[0];
		s1+=bb1[1];
		s2=bb2[0];
		s2+=bb2[1];
		if(s1==s2){
			char a=bb1[2];
			char b=bb2[2];
			if((a>='A' and a<='C') and (b>='A' and b<='C')){
				if(a+1==b or a-1==b){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else if((a>='D' and a<='F') and (b>='D' and b<='F')){
				if(a+2==b or a-2==b){
					cout<<"1111";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
		//cout<<s1<<" "<<s2;
	}else{
		cout<<"0000";
	}
	return 0;
}
