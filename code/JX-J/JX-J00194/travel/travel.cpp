#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool f1=true;
bool f2=true;
bool f3=false;
bool f4=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			f1=false;
			break;
		}
	}
	for(int i=0;i<2;i++){
		if((s1[i]!=s2[i])||(f1==false)){
			f2=false;
			break;
		}
	}
	if((s1[2]=='A')&&((s2[2]=='B')||(s2[2]=='C'))&&(f2==true))f3=true;
	else if((s1[2]=='B')&&((s2[2]=='C')||(s2[2]=='A'))&&(f2==true))f3=true;
	else if((s1[2]=='C')&&((s2[2]=='B')||(s2[2]=='A'))&&(f2==true))f3=true;
	else if((s1[2]=='D')&&(s2[2]=='F')&&(f2==true))f3=true;
	else if((s1[2]=='F')&&(s2[2]=='D')&&(f2==true))f3=true;
	if((f1==true)&&(f2==true)&&(f3==true)&&(abs(s1[2]-s2[2])==1)){
		f4=true;
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
