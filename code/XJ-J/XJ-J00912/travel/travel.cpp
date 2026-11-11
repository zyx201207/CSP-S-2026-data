#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int flag1=0,flag2=0,flag3=0,flag4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		flag4=1;
		if(s1[0]-'0'==s2[0]-'0' && s1[1]-'0'==s2[1]-'0'){
			flag1=1;
				if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
					if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
						flag2=1;
					}
				}
				else{
					if(s2[2]=='C' || s2[2]=='D'){
						flag2=1;
					}
				}
				if(abs((s1[2]-'A')-(s2[2]-'A'))==1){
					if(s1[2]=='C' && s2[2]=='D' || s1[2]=='D' && s2[2]=='C'){
						flag3=0;
					}else{
						flag3=1;
					}
				}
		}
	}
	cout<<flag4<<flag1<<flag2<<flag3;
	return 0;
}