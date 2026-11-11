#include<bits/stdc++.h>
using namespace std;
int c1,c2;	char s1[3],s2[3];
bitset<4>b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){b[3]=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]){b[2]=1;
	if((s1[2]-65<3&&s2[2]-65<3)||(s1[2]-68<3&&s2[2]-68<3&&s1[2]-67>0&&s2[2]-67>0)){b[1]=1;
	if((abs(s1[2]-s2[2])==1&&s1[2]-68&&s2[2]-68)||(s1[2]>67&&s2[2]>67)) b[0]=1;}}}
	cout<<b;	return 0;
}
