#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;


	if(c1==c2){
		ans[0]=1;
	}else{
		ans[0]=0;
	}
	
	if(ans[0]==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		ans[1]=1;
	}else{
		ans[1]=0;
	}
	
	if(ans[1]==1){
		if('A'<=s1[2]&&s1[2]<='C'  &&  'A'<=s2[2]&&s2[2]<='C'){
			ans[2]=1;
		}else{
			if('D'<=s1[2]&&s1[2]<='F'  &&  'D'<=s2[2]&&s2[2]<='F'){
				ans[2]=1;
			}else{
				ans[2]=0;			
			}
		}	
	}else{
		ans[2]=0;
	}
	
	if(ans[2]==1){
		if(char(s1[2])+1 == char(s2[2]) || char(s2[2])+1 == char(s1[2])){
			ans[3]=1;
		}else{
			ans[3]=0;
		}
	}else{
		ans[3]=0;
	}
	
	
	for(int i=0; i<4; i++){
		cout<<ans[i];
	}
	return 0;
}