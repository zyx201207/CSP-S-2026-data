#include <bits/stdc++.h>
using namespace std;
int a=1,b=1,c=1,d=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin>>s1>>c1>>s2>>c2;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			cout<<"0000";
			return 0;
		}
	}
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			cout<<"1000";
			return 0;
		}
	}
	if(c1[2]>='D'&&c2[2]>='F') cout<<"1111";
	else if(c1[2]<='C'&&c2[2]<='C'){
		if(abs(c1[2]-c2[2])==1) cout<<"1111";
		else cout<<"1110";
	}
	else cout<<"1100";
	return 0;
}