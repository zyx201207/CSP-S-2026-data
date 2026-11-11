#include<bits/stdc++.h>
using namespace std;
int a1,a2,a3,a4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) a1=1;
	if(a1&&s2[0]==s4[0]&&s2[1]==s4[1])a2=1;
	if(a2&&(s2[2]<='C'&&s4[2]<='C'||s2[2]>='D'&&s4[2]>='D')) a3=1;
	if(a3&&abs(s2[2]-s4[2])==1) a4=1;
	cout<<a1<<a2<<a3<<a4;
	return 0;
}

