#include<bits/stdc++.h>
using namespace std;
int c1,c2,p1,p2;
char s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>p1>>s1>>c2>>p2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else if(p1!=p2){
		cout<<"1000";
		return 0;
	}
	else if((s1!='D'&&s1!='F')&&(s2=='D'||s2=='F')||(s1=='D'||s1=='F')&&(s2!='D'&&s2!='F')){
		cout<<"1100";
		return 0;
	}
	else if(s1!=s2+1&&s1!=s2-1){
		cout<<"1110";
		return 0;
	}
	else{
		cout<<"1111";
		return 0;
	}
	return 0;
}
