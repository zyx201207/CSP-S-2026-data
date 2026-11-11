#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]=1;
	}
	if(ans[0]&&s1[0]==s2[0]&&s1[1]==s2[1]){
		ans[1]=1;
	}
	if(ans[1]&&((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='E'&&s1[2]<='F'&&s2[2]>='E'&&s2[2]<='F'))){
		ans[2]=1;
	}
	if(ans[2]&&((s1[2]==s2[2]-1)||(s1[2]==s2[2]+1))){
		ans[3]=1;
	}
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
	return 0;
} 
