#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flag1,flag2,flag3,flag4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) flag1=1;
	else flag1=0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]) flag2=1;
	else flag2=0;
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')) flag3=1;
	else flag3=0;
	if(abs(s1[2]-s2[2])==1) flag4=1;
	else flag4=0;
	cout<<flag1<<(flag1&&flag2)<<
	(flag1&&flag2&&flag3)
	<<(flag1&&flag2&&flag3&&flag4);
}
