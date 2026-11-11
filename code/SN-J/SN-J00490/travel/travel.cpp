#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,b1,b2,ans;
int a1,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+="1";
		for(int i=0;i<2;i++){
			b1+=s1[i];
			b2+=s2[i];
		}
		if(b1==b2){
			ans+="1";
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				ans+="1";
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
					ans+="1";
				}else{
					ans+="0";
				}
			}else{
				ans+="00";
			}
		}else{
			ans+="000";
		}
	}else{
		ans+="0000";
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
