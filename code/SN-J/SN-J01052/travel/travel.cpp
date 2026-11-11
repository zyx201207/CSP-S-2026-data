#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,c2;
string s1,s2;
inline bool check(char x,char y){
	if(x<='C'&&y<='C'){
		return 1;
	}
	if(x>='D'&&x<='F'&&y>='D'&&y<='F'){
		return 1;
	}
	return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	system("fc me.out travel1.ans");
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&check(s1[2],s2[2])){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&check(s1[2],s2[2])&&abs((int)s1[2]-(int)s2[2])==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	cout<<endl;
	return 0;
} 
