#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool flag1=true;
	bool flag2=true;
	bool flag3=true;
	bool flag4=false;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			flag1=false;
			break;
		}
	}
	if(flag1==true){
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				flag2=false;
				break;
			}
		}
		if(flag2==true){
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F')){
				flag3=false;
			}
			if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F')){
				flag3=false;
			}
			if(flag3==true){
				if((s2[2]=='D'||s2[2]=='F')&&(s1[2]=='D'||s1[2]=='F')){
					flag4=true;
				}
				else if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
					if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
						flag4=true;
					}
				}
			
			}
			else{
				flag4=false;
			}
		}
		else{
			flag3=false;
			flag4=false;
		}
	}
	else{
		flag2=false;
		flag3=false;
		flag4=false;
	}
    cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
}
