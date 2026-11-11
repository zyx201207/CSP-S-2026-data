#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flag1,flag2,flag3,flag4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		flag1=1;
	}else{
		flag1=0;
	}if(s1[0]==s2[0]&&s1[1]==s2[1]&&flag1){
		flag2=1;
	}else{
		flag2=0;
	}if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')&&flag1&&flag2){
		if(flag1==1&&flag2==1){
			flag3=1;
		}
	}else{
		flag3=0;
	}if((s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')||(int(s1[2]-s2[2])==1)||(int(s2[2]-s1[2]==1))&&flag1&&flag2&&flag3){
		if(flag1==1&&flag2==1&&flag3==1){
			flag4=1;
		}
	}else{
		flag4=0;
	}cout<<flag1<<flag2<<flag3<<flag4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
