#include<bits\stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool b[6]={0,0,0,0,0,0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)b[1]=1;
	if(s1[0]==s2[0] && s1[1]==s2[1] && b[1]==1)b[2]=1;
	if((s1[2]<='C'&&s2[2]<='C' || s1[2]>'C'&&s2[2]>'C')&&b[2]==1)b[3]=1;
	if(abs(s1[2]-s2[2])==1&&b[3]==1)b[4]=1;
	for(int i=1;i<=4;i++)cout<<b[i];
	return 0;
}
