//SN-J00564
#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			bool flag1=0,flag2=0;
			if(s1[2]>='A' && s1[2]<='C') flag1=1;
			if(s2[2]>='A' && s2[2]<='C') flag2=1;
			if(flag1==flag2){
				if(abs(int(s1[2])-int(s2[2]))==1) printf("1111");
				else printf("1110");
			}else{
				printf("1100");
			}
		}else{
			printf("1000");
		}
	}else{
		printf("0000");
	}
	return 0;
}
