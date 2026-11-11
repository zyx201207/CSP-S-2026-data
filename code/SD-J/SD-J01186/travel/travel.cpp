#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
bool f1,f2,f3,f4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) f1=1;
	if(f1&&s1[0]==s2[0]&&s1[1]==s2[1]) f2=1;
	if(f2){
		if(s1[2]=='D'&&s2[2]=='F') f3=1;
		if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')) f3=1;
	}
	if(f3){
		char a=s1[2],b=s2[2];
		if((char)(a-1)==b||(char)(b-1)==a) f4=1;
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}

