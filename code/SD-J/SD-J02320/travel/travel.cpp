#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans=ans+'1';
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1.substr(0,2)==s2.substr(0,2)){
		ans=ans+'1';
	}else{
		cout<<"1000";
		return 0;
	}
	char a1=s1[2],a2=s2[2];
	if((a1=='A'||a1=='B'||a1=='C'&&a2=='A'||a2=='B'||a2=='C')||(a1=='D'||a1=='F'&&a2=='D'||a2=='F')){
		ans=ans+'1';
	}else{
		cout<<"1100";
		return 0;
	}
	if((a1=='D'||a1=='F'&&a2=='D'||a2=='F')||abs(a1-a2)==1){
		cout<<"1111";
	}else{
		cout<<"1110";
	}
	return 0;
}
