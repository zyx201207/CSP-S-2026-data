#include<bits/stdc++.h>
using namespace std;
int c1,c2,f[8]={0,0,0,0,0};
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char a1=s1[2],a2=s2[2];
	if(c1==c2){
		f[1]=1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			f[2]=1;
			if(a1>='A'&& a1<='C' && a2>='A'&& a2<='C'){
				f[3]=1;
				if(abs(a1-a2)==1) f[4]=1;
			}
			else if(a1>='D'&& a1<='F' && a2>='D'&& a2<='F'){
				f[3]=1;
				if(abs(a1-a2)==2) f[4]=1;
			}
		}
	}
	for(int i=1;i<=4;i++) cout<<f[i];
	return 0;
}
