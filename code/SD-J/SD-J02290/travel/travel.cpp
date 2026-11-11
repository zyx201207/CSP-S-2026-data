#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1;
	cin>>c2>>s2;
	bool f1=(c1==c2);
	if(f1==0){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	bool f2=(s1[0]+s1[1]==s2[0]+s2[1]);
	if(!f2){
		cout<<"000";
		return 0;
	}
	bool f3=(abs(s1[2]-s2[2])==1||s1[2]+s2[2]-'A'-'A'==2)&&s1[2]+s2[2]-'A'-'A'!=5;
	if(!f3){
		cout<<"100";
		return 0;
	}
	bool f4=(abs(s1[2]-s2[2])==1);
	if(!f4){
		cout<<"110";
		return 0;
	}
	cout<<"111";
	return 0;
}
