#include<bits/stdc++.h>
using namespace std;
char t[5][5];	
int i1=1,i2=1,i3=0,i4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=4;i++) cin>>t[i];
	for(int i=0;i<2;i++){
		if(t[1][i]!=t[3][i]) i1=0;
		if(t[2][i]!=t[4][i]||i1==0) i2=0;
	}
	if(i2==1){
		if(t[2][2]=='A'||t[2][2]=='B'||t[2][2]=='C') if(t[4][2]=='A'||t[4][2]=='B'||t[4][2]=='C') i3=1;
		if(t[2][2]=='D'||t[2][2]=='F') if(t[4][2]=='D'||t[4][2]=='F') i3=1;
		if(t[2][2]=='A'&&(t[4][2]=='B')) i4=1;
		if(t[2][2]=='C'&&(t[4][2]=='B')) i4=1;
		if(t[2][2]=='B'&&(t[4][2]=='A'||t[4][2]=='C')) i4=1;
		if(t[2][2]=='D'&&(t[4][2]=='F')) i4=1;
		if(t[2][2]=='F'&&(t[4][2]=='D')) i4=1;	
	}
	cout<<i1<<i2<<i3<<i4;
	return 0;
}
