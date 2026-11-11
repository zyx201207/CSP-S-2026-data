#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
char s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b>>s1;
	cin>>c>>d>>s2;
	if (a!=c){
		cout<<"0000";
		return 0;
	}
	if (b!=d){
		cout<<"1000";
		return 0;
	}
	if ((s1>='A' && s1<='C')&&(s2>='D' && s2<='F')||(s2>='A' && s2<='C')&&(s1>='D' && s1<='F')){
		cout<<"1100";
		return 0;
	}
	if (abs(s1-s2)!=1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111"; 
	return 0;
}
