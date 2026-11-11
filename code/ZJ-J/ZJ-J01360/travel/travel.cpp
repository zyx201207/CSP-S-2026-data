#include<bits/stdc++.h>
using namespace std;
int c,cc,r,x,f[10];
string s,ss;
bool ff=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc&&ff) f[1]=1;
	else ff=0;
	r=(s[0]-'0')*10+s[1]-'0';
	x=(ss[0]-'0')*10+ss[1]-'0';
	if(r==x&&ff) f[2]=1;
	else ff=0;
	if(s[2]<='C'&&ff){
		if(ss[2]<='C'){
			f[3]=1;
		}
		else ff=0;
	}
	else if(ss[2]>='C'&&ff){
		if(ss[2]>='C'){
			f[3]=1;
		}
		else ff=0;
	}
	if(abs(s[2]-ss[2])==1&&ff) f[4]=1;
	else ff=0;
	for(int i=1;i<=4;i++){
		cout<<f[i];
	}
}