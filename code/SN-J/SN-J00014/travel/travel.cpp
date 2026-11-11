#include<bits/stdc++.h>
using namespace std;
 
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	 string c1,s1,c2,s2,ans;
	 cin>>c1>>s1>>c2>>s2;
	 
	 if(c1==c2){
	 	ans[1]='1';
	 		if(s1[0]==s2[0]){
	 			if(s1[1]==s2[1]){
	 				ans[2]='1';
	 				if(((s1[2]=='F')||(s1[2]=='D'))&&((s2[2]!='D')||s2[2]!='F')||(((s2[2]=='D')||s2[2]=='F')&&((s1[2]!='F')||(s1[2]!='D')))){
	 					ans[3]='0';
	 					cout<<"1100";
						 return 0; 
					 }else{
					 	ans[3]='1';
					 }
					
		 		}else{
		 			cout<<"1000"; 
		 			return 0;
				}
	 		}
	 		if((s1[2]==s2[2]+1)||(s1[2]==s2[2]-1)){
	 						ans[4]='1';
					 	}else{
					 		ans[4]='0';
						 }
	 	
	 }else{
	 	cout<<"0000";
	 	return 0;
	 }
	

	for(int i=1;i<=4;i++){
		cout<<ans[i]; 
	}
	
	
	
	return 0;
}
