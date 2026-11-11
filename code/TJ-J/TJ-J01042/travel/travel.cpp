#include<bits/stdc++.h>
using namespace std;
string str1,str2,str3,str4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>str1>>str2>>str3>>str4;
	char str5[4];
	str5[0]=48;
	str5[1]=48;
	str5[2]=48;
	str5[3]=48;
	if(str1==str3){
		str5[0]=49;
		if(str2[0]==str4[0] and str2[1]==str4[1]){	
				str5[1]=49;
			if((str2[2]==67 and str4[2]==68)or(str2[2]==68 and str4[2]==67)){
				str5[2]=48;
			}
			else{
				str5[2]=49;
			if((str2[2]==65 and str4[2]==66) or (str2[2]==66 and str4[2]==67) or (str2[2]==68 and str4[2]==70)or(str4[2]==65 and str2[2]==66) or (str4[2]==66 and str2[2]==67) or (str4[2]==68 and str2[2]==70)){				
				str5[3]=49;
			}
		}
	}
}
for(int i=0;i<4;i++)cout<<str5[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
