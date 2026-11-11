#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[1]!=s2[1]||s1[0]!=s2[0]){
		cout<<"1000";
		return 0;
	}
	if((s1[2]>='D'&&s2[2]<='C')||(s2[2]>='D'&&s1[2]<='C')){
		cout<<"1100";
		return 0;
	}
	if(((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C'))||(s1[2]=='D'&&s2[2]=='F')){
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0;
}
