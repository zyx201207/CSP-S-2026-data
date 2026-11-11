#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ans1,ans2=1,ans3,ans4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans1=1;
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				ans2=0; 
			} 
		}if(ans2&&(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
			ans3=1;
			if(abs(s1[2]-s2[2])==1){
				ans4=1;
			}
		}
	}
	if(!ans1){
		ans2=0;
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
} 
