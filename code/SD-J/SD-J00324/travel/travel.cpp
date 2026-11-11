#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int a=0,b=0,c=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
	cout<<1;
	a=1;
	}
	else cout<<0;
	if(a==1&&(s1[0]==s2[0]&&s1[1]==s2[1])){
	cout<<1;
	b=1;
	}
	else cout<<0;
	if(b==1&&(s1[0]==s2[0]&&s1[1]==s2[1]&&((s1[2]<=67&&s2[2]<=67)||(s1[2]>=68&&s2[2]>=68)))){
	cout<<1;
	c=1;
	}
	else cout<<0;
	if(c==1&&(s1[2]-2==s2[2]||s1[2]+2==s2[2])) cout<<1;
	else cout<<0;
	return 0;
} 
