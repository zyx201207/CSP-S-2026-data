#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,c2,f;
string s1,s2;
char c='A';
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		f=1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if((s1[0]*10+s1[1]==s2[0]*10+s2[1])&&f==1){
		cout<<1;
		f=2;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(f==2&&((s1=="F"||s1=="D")&&(s2=="F"||s2=="D")||(s1=="A"||s1=="B"||s1=="C")&&(s2=="A"||s2=="B"||s2=="C"))){
		cout<<1;
		f=3;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(f==3&&){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
