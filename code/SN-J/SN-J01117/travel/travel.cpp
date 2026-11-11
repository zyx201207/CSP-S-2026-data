#include <iostream>
using namespace std;
int main£¨£©{
	//freopen("trawle.in","r",stdin);
    //freopen("trawle.out","w",stdout);
	string c1,s1,c2,s2;
	string zzz;
	zzz.size[]=4
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==s1[0]&&c1[1]==s1[1]){zzz[0]=1;}
	else{zzz[0]=0;}
	if(c2[1]='A'&&s2[1]=='B'){zzz[1]=1;}
	else if(c2[2]='B'&&s2[2]=='A'){zzz[2]=1;zzz[3]=1;}
	else if(c2[2]='B'&&s2[2]=='C'){zzz[2]=1;zzz[3]=1;}
	else if(c2[2]='C'&&s2[2]=='B'){zzz[2]=1;zzz[3]=1;}
	else if(c2[2]='D'&&s2[2]=='E'){zzz[2]=1;zzz[3]=1;}
	else if(c2[2]='E'&&s2[2]=='D'){zzz[2]=1;zzz[3]=1;}
	else{zzz[0]=0;zzz[2]=0;zzz[1]=0;zzz[03]=0;}
	cout<<zzz;
return 0;}
