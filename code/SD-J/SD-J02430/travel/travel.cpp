#include<bits\stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	if((s1[2]-'A'<=2&&s2[2]-'A'<=2)==0&&(s1[2]-'A'>=3&&s2[2]-'A'>=3)==0){
		cout<<"1100";
		return 0;
	}
	if(s1[2]-'A'<=2&&s2[2]-'A'<=2){
		if((s1[2]-s2[2]==1||s2[2]-s1[2]==1)==0){
			cout<<"1110";
			return 0;
		}
	}
	cout<<"1111";
	return 0;
}
