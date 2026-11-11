#include<bits/stdc++.h>
using namespace std;
int c1,c2,x1,x2,a1,a2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x1=s1[0]*10+s1[1];
	x2=s2[0]*10+s2[1];
	a1=s1[2]-'A';
	a2=s2[2]-'A';
	if(c1==c2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(x1==x2)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(a1<3&&a2<3||a1>=3&&a2>=3)cout<<1;
	else{
		cout<<"00";
		return 0; 
	}
	if(abs(a1-a2)==1)cout<<1;
	else cout<<0;
	return 0;
}

