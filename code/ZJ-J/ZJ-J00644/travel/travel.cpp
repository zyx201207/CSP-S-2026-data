#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0] || s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	bool x1=(s1[2]<='C'),x2=(s2[2]<='C');
	if(x1!=x2){
		cout<<"1100";
		return 0;
	}
	char ch1=s1[2],ch2=s2[2];
	if(max(ch1,ch2)-1!=min(ch1,ch2)) cout<<"1110";
	else cout<<"1111";
	

	return 0;
}
