#include<bits/stdc++.h>
using namespace std;
bool ff(string s1,string s2){
	for(int i=0;i<2;i++)
			if(s1[i]!=s2[i])return 0;
	return 1;
}
bool fff(string s1,string s2){
	if((s1[2]=='F'||s1[2]=='D')&&(s2[2]=='F'||s2[2]=='D'))return 1;
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))return 1;
	return 0;
}
bool ffff(string s1,string s2){
	if(abs(s1[2]-s2[2])==1)return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w".stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool f1=0,f2=0,f3=0,f4=0;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		f1=1;
		f2=ff(s1,s2);
		if(f2)f3=fff(s1,s2);
		if(f3){
			f4=ffff(s1,s2);
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0; 
} 
