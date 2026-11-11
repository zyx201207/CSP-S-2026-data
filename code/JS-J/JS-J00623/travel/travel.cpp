#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int o[5];
bool beside1(string c1,string c3){
	for(int i=0;i<2;i++)
		if(c1[i]!=c3[i])
			return false;
	return true;
}
bool beside2(string c2,string c4){
	for(int i=0;i<2;i++)
		if(c2[i]!=c4[i])
			return false;
	return true;
}
bool beside3(string c2,string c4){
	if(c2[2]>='D'&&c4[2]<='D')
		return false;
	if(c2[2]<='D'&&c4[2]>='D')
		return false;
	return true;
}
bool beside4(string c2,string c4){
	int a=c2[2],b=c4[2];
	if(a-b==1||a-b==-1)
			return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(beside1(c1,c3)) cout<<1; else cout<<0;
	if(beside2(c2,c4)&&beside1(c1,c3)) cout<<1; else cout<<0;
	if(beside3(c2,c4)&&beside2(c2,c4)&&beside1(c1,c3)) cout<<1; else cout<<0;
	if(beside4(c2,c4)&&beside3(c2,c4)&&beside2(c2,c4)&&beside1(c1,c3)) cout<<1; else cout<<0;
		
		return 0;
}
