#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool cmp(){
	if(s1[2]<'D'&&s2[2]<'D')return 1;
	if(s1[2]>'C'&&s2[2]>'C')return 1;
	return 0;
}
bool next_to(){
	char c1=s1[2],c2=s2[2];
	if(c1=='A'&&c2=='B')return 1;
	if(c1=='B'&&c2=='A')return 1;
	if(c1=='C'&&c2=='B')return 1;
	if(c1=='B'&&c2=='C')return 1;
	if(c1=='F'&&c2=='D')return 1;
	if(c1=='D'&&c2=='F')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//  no"//"!!!
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	bool k1=0,k2=0,k3=0,k4=0;
	if(c1==c2){
		k1=1;
	}
	if(k1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		k2=1;
	}
	if(k2&&cmp()){
		k3=1;
	}
	if(k3&&next_to()){
		k4=1;
	}
	cout<<k1<<k2<<k3<<k4;
	return 0;
}
