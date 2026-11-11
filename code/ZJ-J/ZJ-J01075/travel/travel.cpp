#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	
	if(((int)s1[0]==(int)s2[0])&&((int)s1[1]==(int)s2[1])) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	
	int gd1=1,gd2=1;
	if((int)s1[2]=='D'||(int)s1[2]=='F') gd1=2;
	if((int)s2[2]=='D'||(int)s2[2]=='F') gd2=2;
	
	if(gd1==gd2) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	
	if(gd1==gd2){
		if(gd1==2&&gd2==2) cout<<1;
		else if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')) cout<<0;
		else cout<<1;
	}else cout<<0;
	return 0;
}
