#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
bool f[5]={false,false,false,false};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) f[0]=true;
	if(s1[0]==s2[0] && s1[1]==s2[1]) f[1]=true;
	if((s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C') || (s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F')){
		f[2]=true;
	}
	if(abs(int(s1[2]-s2[2]))==1) f[3]=true;
	for(int i=0;i<4;i++){
		if(f[i]==true) cout<<'1';
		else f[i+1]=false,cout<<'0';
	}
	return 0;
}
