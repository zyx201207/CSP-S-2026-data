#include<bits/stdc++.h>
using namespace std;
bool check(char x,char y){
	if(min((int)x,(int)y)<='C'&&max((int)x,(int)y)>='D')return 0;
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(!(s1[0]==s3[0]&&s1[1]==s3[1])){
		cout<<"0000";
		return 0;
	}else if(!(s2[0]==s4[0]&&s2[1]==s4[1])){
		cout<<"1000";
		return 0;
	}else if(!check(s2[2],s4[2])){
		cout<<"1100";
		return 0;
	}else if(!(min((int)s2[2],(int)s4[2])+1==max((int)s2[2],(int)s4[2]))&&!(min((int)s2[2],(int)s4[2])=='D'&&max((int)s2[2],(int)s4[2])=='F')){
		cout<<"1110";
		return 0;
	}else{
		cout<<"1111";
		return 0;
	}
	return 0;
} 
