#include <bits/stdc++.h>
using namespace std;
string s1,s2;
char a,b,c,aa,bb,cc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>a>>b>>c;
	cin>>s2>>aa>>bb>>cc;
	if(s1==s2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	int z=0;
	if(s1==s2&&a==aa&&b==bb){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	if(s1==s2&&a==aa&&b==bb&&((c<='C'&&cc<='C')||(c>'C'&&cc>'C'))){
		cout<<"1";
		z=1;
	}else{
		cout<<"0";
	}
	int x=(int)c;
	int y=(int)cc;
	if(z&&abs(x-y)==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}