#include <bits/stdc++.h>
using namespace std;
#define ll long long
string c_1,c_2;
string s_1,s_2;
bool ans[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1[0]==c_2[0]&&c_1[1]==c_2[1]){
		ans[0]=1;	
		if(s_1[0]==s_2[0]&&s_1[1]==s_2[1]){
		
			ans[1]=1;
			if(s_1[2]<='C'&&s_2[2]<='C'){
				ans[2]=1;
				if(abs(s_1[2]-s_2[2])==1) ans[3]=1;
			}else if((s_1[2]>='D'&&s_1[2]<='F')&&(s_2[2]>='D'&&s_2[2]<='F')){
				ans[2]=ans[3]=1;
			}
		}
 	}
 	for(int i=0;i<4;i++) cout<<ans[i];
	return 0;
}
