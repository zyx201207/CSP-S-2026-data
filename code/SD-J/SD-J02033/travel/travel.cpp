#include<bits/stdc++.h>
using namespace std;
int main(){
	 freopen("travel.in","r",stdin);
	 freopen("travel.out","w",stdout);
	 char c1,s1,c2,s2;
	 cin>>c1>>s1>>c2>>s2;
	 for(int i=1;i<=s1;i++){
	 	for(int i=1;i<=s2;i++){
	 		if(s1==s2){
	 			cout<<"0";
			 }else{
			 	cout<<"1";
			 }
		 }
	}
	if(c1==c2&&s1==s2){
		cout<<"1111";
	}else{
		cout<<"0000";
	}
 return 0;
 }

