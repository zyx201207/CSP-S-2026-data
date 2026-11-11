#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(s1[0]*10+s1[1]!=s2[0]*10+s2[1]){
		cout<<"000";
		return 0;
	} else {
		cout<<"1";
	}
	int z1=s1[2]-'A',z2=s2[2]-'A';
	bool b=1;
	if(z1<=2&&z2<=2||z1>2&&z2>2){
		cout<<"1";
	} else {
		cout<<"0";
		b=0;
	}
	if(b==0){
		cout<<"0";
	} else if(z1==2&&z2==3||z1==3&&z2==2||z1==0&&z2==2||z1==2&&z2==0){	
		cout<<"0";		
	} else {
		cout<<"1";
	}
	return 0;
}