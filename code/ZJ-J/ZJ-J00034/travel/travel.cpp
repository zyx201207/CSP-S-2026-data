#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int k1,k2,k3,k4;
	if(c1==c2){
		k1=1;
	}
	else {
		k1=0;
	}
	if(k1==1&&s2[0]==s1[0]&&s2[1]==s1[1]){
		k2=1;
	}
	else {
		k2=0;
	}
	if(k2==1&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>='D'))){
		k3=1;
	}
	else {
		k3=0;
	}
	if(k2==1&&k3==1&&abs(s1[2]-s2[2])==1){
		k4=1;
	}
	else {
		k4=0;
	}
	cout<<k1<<k2<<k3<<k4;
	return 0;
}