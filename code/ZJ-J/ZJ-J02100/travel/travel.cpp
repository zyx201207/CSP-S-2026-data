//T1 travel 解法1 预期100
//Trick||Treat!
#include <bits/stdc++.h>
//#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		printf("1");
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			printf("1");
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					printf("1");
					if((s1[2]==s2[2]+1)||(s1[2]==s2[2]-1)) printf("1");
					else printf("0");
				}
				else printf("00");
			}else if(s1[2]=='D'||s1[2]=='F'){
				if(s2[2]=='D'||s2[2]=='F'){
					printf("1");
					if((s1[2]==s2[2]+1)||(s1[2]==s2[2]-1)) printf("1");
					else printf("0");
				}
				else printf("00");
			}
		}
		else printf("000");
	}
	else printf("0000");
}