#include<bits/stdc++.h>
using namespace std;
string c1,st1,c2,st2;
bool f[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>st1>>c2>>st2;
	if(c1==c2){
		f[1]=1;
	}
	if(f[1]&&st1[0]==st2[0]&&st1[1]==st2[1]){
		f[2]=1;
	}
	if(f[2]&&(st1[2]<='C'&&st2[2]<='C'||st1[2]>='D'&&st2[2]>='D')){
		f[3]=1;
	}
	if(f[3]&&(st1[2]<='C'&&st2[2]<='C'&&abs(st1[2]-st2[2])==1||st1[2]=='D'&&st2[2]=='F'||st1[2]=='F'&&st2[2]=='D')){
		f[4]=1;
	}
	for(int i=1;i<=4;i++){
		if(f[i])cout<<"1";
		else cout<<"0";
	}
	return 0;
}
