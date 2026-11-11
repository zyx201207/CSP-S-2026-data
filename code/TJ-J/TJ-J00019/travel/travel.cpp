#include <bits/stdc++.h>
using namespace std;
#define int long long
int c1,c2;
string s1,s2; 
signed main(){
	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0] || s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	if((3>=s1[2]-64>=1 && 3>=s2[2]-64>=1) || (6>=s1[2]-64>=4 && 6>=s1[2]-64>=4)) int a=1;
	else{
		cout<<"1100";
		return 0;
	}
	if(s1[2]+1==s2[2] || s1[2]-1==s2[2]) int a=0;
	else{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0; 
}
