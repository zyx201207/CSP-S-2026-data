#include<algorithm>
#include<cmath>
#include<string>
#include<deque>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,l1,l2;
	char a1,a2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	l1=(s1[0]-'0')*10+s1[1]-'0';
	a1=s1[2];
	l2=(s2[0]-'0')*10+s2[1]-'0';
	a2=s2[2];
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(l1==l2){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((a1<='C'&&a2<='C')||(a1>='D'&&a2>='D')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if((a1=='A'&&a2=='B')||(a1=='B'&&a2=='C')||(a1=='B'&&a2=='A')||(a1=='C'&&a2=='B')||(a1=='D'&&a2=='F')||(a1=='F'&&a2=='D')){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
