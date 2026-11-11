#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]!=s2[i]){
			cout<<"1000";
			return 0;
		}
	}
	if((s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&(s2[2]=='B'||s2[2]=='A'))||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
		if(abs(((int)s1[2]-(int)s2[2]))==1||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')){
			cout<<"1111";
			return 0;
		}
		cout<<"1110";
		return 0;
	}
	else{
		cout<<"1100";
		return 0;
	}
	return 0;
}
