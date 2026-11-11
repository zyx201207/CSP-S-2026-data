#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
bool f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	char cr2=c2[2],cr4=c4[2];
	if(c1==c3)f1=1;
	if(c2[0]==c4[0]&&c2[1]==c4[1]&&f1==1)f2=1;
	if((cr2<='C'&&cr4<='C'||cr2>='D'&&cr4>='D')&&f2==1)f3=1;
	if(f3==1){
		if(cr2=='B'||cr4=='B')f4=1;
		if(cr2=='D'||cr4=='D')f4=1;
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
