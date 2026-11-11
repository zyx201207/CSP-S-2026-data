#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
	}if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && 'A'<=s1[2] && s1[2]<='C' && 'A'<=s2[2] && s2[2]<='C'){
		cout<<1;
		
	}else if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && 'D'<=s1[2] && s1[2]<='E' && 'D'<=s2[2] && s2[2]<='E'){
		cout<<1;
	}else{
		cout<<0;
	}
//	int n=,m=s2[0]-'0'+s2[1]-'0';
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && 'A'<=s1[2] && s1[2]<='C' && 'A'<=s2[2] && s2[2]<='C' && abs(s1[2]-s2[2])==1){
		cout<<1;
	}else if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && 'D'<=s1[2] && s1[2]<='E' && 'D'<=s2[2] && s2[2]<='E' && abs(s1[2]-s2[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}



	return 0;
}
